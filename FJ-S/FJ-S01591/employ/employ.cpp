#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,m,c[N],p[N];
long long ans;
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];p[i]=i;
	}
	do{
		int cur=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1')	cur++;
			else if(cur>=c[p[i]])	cur++;
		}
		if(n-cur>=m)	ans++;
	}while(next_permutation(p,p+n));
	cout<<ans%998244353;
	return 0;
} 
