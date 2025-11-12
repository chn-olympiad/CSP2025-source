#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[505];
long long ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int s1=1,s2=1;
	for(int i=1;i<=n;i++){
		s1*=i;
		s1%=N;
	}
	for(int i=1;i<=n-m;i++){
		s2*=i;
		s2%=N;
	}
	ans=(s1/s2)%N;
	bool f=1;
	for(int i=0;i<int(s.size());i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}
	if(f==1){
		if(m!=n){
			cout<<"0";
			return 0;
		}else{
			cout<<ans;
			return 0;
		}
	}
	if(m==n){
		if(f==1){
			cout<<ans;
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
