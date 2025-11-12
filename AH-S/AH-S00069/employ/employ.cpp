#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
int c[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	vector<int> xb(n);
	for(int i=0;i<n;i++) xb[i]=i;
	long long ret=0;
	do{
		vector<int> a(n);
		for(int i=0;i<n;i++) a[i]=c[xb[i]];
		int cnt=0,wt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0' || wt>=a[i]){
				wt++;
			}else{
				cnt++;
			}
		}
		if(cnt>=m){
			ret++;
			ret%=inf;
		}
	}while(next_permutation(xb.begin(),xb.end()));
	
	cout<<ret%inf<<"\n";
    return 0;
}
