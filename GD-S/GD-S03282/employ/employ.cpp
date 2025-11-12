#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=998244353;
int n,m,a[10001],b[10001],cnt=0,k=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>b[i],a[i]=i;
//	sort(a+1,a+1+n);
	do{
//		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//		cout<<' ';
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=b[a[i]])cnt++;
			else if(s[a[i]]=='0'){
				cnt++;
			}
		}
		if(n-cnt>=m){
			k=(k+1)%N;
		}
//		cout<<k<<'\n';
	}while(next_permutation(a+1,a+1+n));
	cout<<k<<'\n';
	return 0;
}
