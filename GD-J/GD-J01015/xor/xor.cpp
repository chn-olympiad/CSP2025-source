#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],n,k,vis[N],cnt;
string zh(int v){
	string s="",m="";
	while(v){
		s+=v%2+'0'; 
		v/=2;
	}
	for(int i=s.size()-1;i>=0;i--) m+=s[i];
	return m;
}
int yh(int r,int b){
	int ans=0;
	for(int i=r+1;i<=b;i++){
		string s1=zh(ans),s2=zh(a[r]);
		int t=max(s1.size()-1,s2.size()-1);
		for(int i=0;i<=t;i++){
			if(zh(ans)[i]!=zh(a[i])[i]) ans+=pow(2,t-i);
		}
	}
	return ans;
}
int check(int mid){
	int t=0,ans=a[1];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(yh(i,j)==k){
				ans++;
			
			}
		}
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
	}else if(k<=1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
			else if(a[i+1]==1){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
	}else{
		cout<<check(1);
	}
	return 0;
}

