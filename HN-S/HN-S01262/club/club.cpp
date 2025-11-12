#include<bits/stdc++.h>
using namespace std;
int n,t,s[10100][4],x1=0,x2=0,x3=0,Max=0,p=1,ans=0;
void cnt(int m){
	p++;
	if(x1>n/2||x2>n/2||x2>n/2){
		return ;
	}
	if(p=n){
		if(ans>Max){
			Max=ans;
			ans=0;
			return ;
		}
	}
	p++;
	for(int l=1;l<=3;l++){
		ans+=m;
		cnt(s[p][l]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
	}
	for(int i=1;i<=3;i++){
		cnt(s[p][i]);
	}
	cout<<Max;
	return 0;
}
