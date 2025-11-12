#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005][3],b[3];
int re;
void f(int k,int s){
	if(k>m){
		re=max(re,s);
		return;
	}
	for(int j=0;j<3;j++){
		if(b[j]==m/2)continue;
		b[j]++;
		f(k+1,s+a[k][j]);
		b[j]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		re=0;
		cin>>m;
		for(int i=1;i<=m;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		f(1,0);
		cout<<re<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%



