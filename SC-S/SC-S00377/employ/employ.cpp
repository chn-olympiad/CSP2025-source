#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,MAXN=510;
int n,m;
int c[MAXN];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1){
		int num=0;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='1'){
				num=i+1;
				break;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=num) cnt++;
		}
		if(cnt+1<num) cout<<"0";
		else{
			long long ans=1;
			int temp=num-1,temp2=cnt;
			while(temp--){
				ans=(ans*temp2)%mod;
				temp2--;
			}
			
			n-=num;
			for(int i=2;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		return 0;
	}
	if(m==n){
		int len=s.size();
		bool flag=false;
		for(int i=0;i<len;i++){
			if(s[i]=='0'){
				flag=true;
				break;
			}
		}
		if(!flag){
			long long ans=1;
			for(int i=2;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}else cout<<"0";
		
		return 0;
	}
	else{
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	return 0;
}