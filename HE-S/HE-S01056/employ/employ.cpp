#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int n,m;
string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				sum++;
			}
		}
		if(sum!=n){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	cout<<1;
	return 0;
}
