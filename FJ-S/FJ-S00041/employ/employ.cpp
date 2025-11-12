#include<bits/stdc++.h>
using namespace std;
const int N=504;
int n,m,s[N],c[N],f[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch=='1';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)f[i]=i;
	int ans=0;
	do{
		int tmp=0;
		for(int i=1;tmp<m&&i<=n;i++)tmp+=s[i]&&i-tmp<=c[f[i]];
		ans+=tmp>=m;
	}while(next_permutation(f+1,f+n+1));
	cout<<ans;
}
