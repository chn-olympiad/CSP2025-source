#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
int n,K; 
int a[500100];
bool st[500100];
string qwq(int x){//logx   20
	string s;
	while(x>0){
		int t=x%2;
		char c=t+'0';
		s=c+s;
		x/=2;
	} 
	return s;
}
int ksm(int x,int y){
	int ans=1;
	while(y>0){
		if(y%2)ans*=x;
		y/=2;
		x=x*x;
	}
	return ans;
}
string as(string x,string y){
	int xx=x.size();
	int yy=y.size();
	if(xx>yy){
		for(int i=1;i<=xx-yy;i++){
			y='0'+y;
		}
	}else {
		for(int i=1;i<=yy-xx;i++){
			x='0'+x;
		}
	}
	int q=max(xx,yy);
	string t;
	for(int i=0;i<q;i++){
		if(x[i]==y[i]){
			t=t+'0';
		}else t=t+'1';
	} 
	return t;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	if(K==0&&n<=2){
		if(n==1)cout<<0;
		if(n==2)cout<<1;
		return 0;
	}
	string k=qwq(K);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,la=1;
	for(int i=1;i<=n;i++){
		if(a[i]==K&&st[i]==0){
			ans++;
			st[i]=1;
			la=i;
			continue;
		}
		string s=qwq(a[i]);
		for(int j=i+1;j<=n;j++){
			if(a[j]==0)continue;
			s=as(s,qwq(a[j]));
			if(s==k){
				ans++;
				st[j]=1;
				la=j;
			}
		}
	}
	cout<<ans; 
} 
