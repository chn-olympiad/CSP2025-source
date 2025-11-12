#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500050];
struct node{
	int l,r=INT_MAX,len;
}s[500050],dp[500050][2];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int f(int st,int ed){
	int num=a[st];
	for(int i=st+1;i<=ed;i++){
		num=(num xor a[i]);
	}
	return num;
}
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int tot=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(f(i,j)==k){
				ans++;
				s[++tot].l=i;
				s[tot].r=j;
				s[tot].len=j-i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
