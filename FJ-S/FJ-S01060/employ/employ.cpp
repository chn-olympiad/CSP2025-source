#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int ans=0;
vector<int> k;
int n,m,c[510];
string s;
void solve2(vector<int> num){
	int t=0,l=0;
	for(int i=0;i<num.size();i++){
//		cout<<num[i]<<" ";
		int nw=num[i];
		if(s[i]=='0'||c[nw]<=t){
			t++;
			continue;
		}
		l++;
	}
//	puts("");
	if(l>=m) ans++;
}
bool b[1000]={0};
void solve(vector<int> num){
	if(num.size()==n){
		solve2(num);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==1) continue;
		b[i]=1;
		num.push_back(i);
		solve(num);
		num.pop_back();
		b[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	bool bb=0;
	int sums[1000]={0};
	if(s[0]=='0') sums[0]=1;
	for(int i=1;i<s.size();i++){
		sums[i]=sums[i-1];
		if(s[i]=='0') sums[i]++;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') sums[i]=1e9+7,bb=1;
	}
	if(bb==0){
		int l=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0) l--;
		}
		if(m==l){
			int ans=1;
			for(int i=2;i<=l;i++){
				ans*=i;
			}
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	vector<int> num;
	if(n<=10){
		solve(num);
		cout<<ans;
		return 0;
	}
	if(m==n){
		int t=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
//	if(m==1){
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			if(c[i]>sums[i]){
//				int las=-1,len=0,zs=0;
//				int anss=1;
//				for(int j=0;j<n;j++){
//					if(j+1==i) continue;
//					if(las!=sums[i]){
//						int sz=0;
//						for(int ii=1;ii<=n;ii++){
//							if(c[ii]<=las) sz++;
//						}
//						int l=sz-zs;
//						if(l-len<0){
//							cout<<0;
//							return 0;
//						}
//						int xans=1;
//						for(int i=zs+1;i<=sz;i++){
//							xans*=i;
//						}
////						cout<<sz<<" ";
//						anss*=xans;
//						zs+=len;
//						las=sums[i];
//						len=1;
//					}
//					len++;
//				}
//				ans+=anss;
//						int sz=0;
//						for(int ii=1;ii<=n;ii++){
//							if(c[ii]<=las) sz++;
//						}
//						int l=sz-zs;
//						if(l-len<0){
//							cout<<0;
//							return 0;
//						}
//						int xans=1;
//						for(int i=zs+1;i<=sz;i++){
//							xans*=i;
//						}
//						ans*=xans;
//						zs+=len;
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
	cout<<0;
	return 0;
}
