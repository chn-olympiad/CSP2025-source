#include<bits/stdc++.h>
using namespace std;
int n,m,t,s[101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	t=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			if(s[i*m+j]==t){
				if((i+1)%2)cout<<i+1<<' '<<j;
				else cout<<i+1<<' '<<m-j+1;
				return 0;
			}
}
