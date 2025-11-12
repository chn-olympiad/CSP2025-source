#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int c[505];
int p[15];
string s;

int main(){
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	int ans=0;
	s=" "+s;
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=cnt||s[i]=='0')cnt++;
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
