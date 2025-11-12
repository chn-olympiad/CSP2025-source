#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;

int in(){
	int t=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return t*k;
}

void out(int x){
	if(x<0)x=-x,putchar('-');
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10);putchar(x%10+'0');
}


int n,m;
int t[N<<2];

void pushup(int rt){
	t[rt]=t[rt<<1]^t[rt<<1|1];
}

void build(int l,int r,int rt){
	if(l>=r){
		t[rt]=in();
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=r){
		return t[rt];
	}
	int ans=0,mid=(l+r)>>1;
	if(mid>=L)ans^=query(L,R,l,mid,rt<<1);
	if(mid<R)ans^=query(L,R,mid+1,r,rt<<1|1);
	return ans;
}

int dp[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	n=in(),m=in();
	build(1,n,1);
	if(m==0){
		
	}
	//cout<<query(2,4,1,n,1);
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if(query(l,r,1,n,1)==m)dp[l][r]++;
			for(int k=l;k<r;k++){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]); 
			}
		}
	}
	out(dp[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*

*/