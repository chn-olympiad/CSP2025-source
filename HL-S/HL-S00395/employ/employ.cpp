#include<bits/stdc++.h> 
using namespace std;
int n,m;
char s[500];int c[500];
bool amp(int a,int b){
	return a<b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		s[i]=getchar();
		if(ma==0 && s[i]==1)ma=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,amp);
	int a=1;
	while(c[a+1]<m){
		a++;
	}
	cout<<n*n;
}
