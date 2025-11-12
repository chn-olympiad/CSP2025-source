#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5010];
set <string> st;
bool is1=true;
unsigned long long fun(int a1,int a2){
	unsigned long long ans=1;
	for(int i=a2+1;i<=a1;i++){
		ans*=i;
	}
	for(int i=1;i<=a1-a2;i++){
		ans/=i;
	}
	return ans;
}
void dfs(int j,int cnt,int len,int maxx,string s){
	if(cnt>=3){
		int tmp=0;
		for(int i=0;i<s.size();i++){
			tmp+=a[s[i]-'0'];
		}
		if(tmp>a[s[s.size()-1]-'0']*2){
			st.insert(s);
		}
	}
	if(n-j+1+cnt<=2){
		return ;
	}
	for(int i=j;i<=n;i++){
		char c=(i+'0');
		if(len+a[i]>a[i]*2||cnt<3){
			dfs(i+1,cnt+1,len+a[i],a[i],s+c);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			is1=false;
		}
	}
	if(n<3){
		cout<<"0";
		return 0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]<=max(a[1],max(a[2],a[3]))*2){
			cout<<"0";
		}else{
			cout<<"1";
		}
		return 0;
	}else if(is1==true){
		unsigned long long tmp=0;
		for(int i=3;i<=n;i++){
			tmp+=fun(n,i);
			tmp%=mod;
		}
		cout<<tmp%mod;
		return 0;
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0,0,"");
		int tmp=0;
		string s="";
		char c;
		for(int i=1;i<=n;i++){
			c=i+'0';
			tmp+=a[i];
			s+=c;
		}
		if(tmp>a[n]*2){
			st.insert(s);
		}
		cout<<st.size()%mod;
	}
	return 0;
}
