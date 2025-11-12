#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int N=510,mod=998244353;
int c[N],p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int ans=1;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	bool fl=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			fl=1;break;
		}
	}
	if(!fl){
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<"\n";
		return 0; 
	}
	ans=0;
	do{
//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//		cout<<"\n";
		int cnt=0,op=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;continue;
			}
			if(cnt>=c[p[i]]){
				cnt++;continue;
			}
			op++;
//			cout<<op<<" "<<cnt<<"\n";
		}
//		cout<<"\n";
		if(op>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n"; 
	return 0;
}
/*
3 2
101
1 1 2
*/
