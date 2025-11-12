#include<bits/stdc++.h>
#define ll long long
#define md 998244353
using namespace std;
int n,p[501],a[501],m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[i]=i;
	int ans=0;
	do{
		int sum=0,ss=0;
		for(int i=1;i<=n;i++){
			if(a[p[i]]<=sum){sum++;continue;}
			if(s[i-1]=='1')ss++;
			else sum++;
		}
		if(ss>=m)ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<'\n';
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

 */