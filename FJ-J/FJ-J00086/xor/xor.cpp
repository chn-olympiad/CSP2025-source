#include<bits/stdc++.h>
using namespace std;
int n,k,num;
int a[500005],dp[500005];
bool flag=1;
struct node{
	int l,r;
}b[500005];
void push(int l,int r){
	b[++num].l=l;
	b[num].r=r;
}
void idx(){
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i;j<=n;j++){
			if(j!=i)sum^=a[j];
			if(sum==k)push(i,j);
		}
	}
}
bool pd(node x,node y){
	if(x.l<y.l)return true;
	else if(x.l==y.l)
		if(x.r<y.r)return true;
	return false;
}
inline int read(){
	int res=0,fu=1;
	char c;
	while(!isdigit(c)){
		if(c=='-')fu=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=(res<<3)+(res<<1)+(c-48);
		c=getchar();
	}
	return res*fu;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)flag=0;
	}
	if(flag)printf("%d",n/2);
	else{
		idx();
		sort(b+1,b+1+num,pd);
		for(int i=1;i<=num;i++){
			int maxn=1;
			for(int j=1;j<i;j++)
				if(b[j].r<b[i].l)
					maxn=max(maxn,dp[j]+1);
			dp[i]=maxn;
		}
		int ans=0;
		for(int i=1;i<=num;i++)
			ans=max(ans,dp[i]);
		printf("%d",ans);
	}
	return 0;
}

