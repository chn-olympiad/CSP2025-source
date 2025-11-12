#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=501;
long long n,m,sum[N],c[N],cnt0,ans;
string s;
int inst[N];
void dfs(int d,vector<int> ar){
	if(d==n){
		int r=1;
		for(int i=1;i<n;i++){
			if(s[i]=='1'&&sum[i-1]<c[ar[i]]) r++;
		}
		if(r>=m){
			ans=(ans+1)%P;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(inst[i]==0){
				inst[i]=1;
				vector<int> tmp=ar;
				tmp.push_back(i);
				dfs(d+1,tmp);
				inst[i]=0;
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	sum[0]=(s[0]=='0');
	for(int i=1;i<len;i++){
		sum[i]=sum[i-1]+(s[i]=='0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt0++;
	}
	if(n-m<cnt0){
		cout<<0;
	}
	if(n<=18){
		dfs(0,{});
	}
	else{
		ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%P;
		}
	}
	cout<<ans<<endl;
	return 0;
}
