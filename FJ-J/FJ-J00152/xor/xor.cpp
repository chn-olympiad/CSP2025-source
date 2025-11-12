#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans=0;
	char c;
	c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0' && c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
long long n,k,a[555555],dp[555555];
mt19937 rnd(223);
struct str{
	long long key,val,l,r;
	long long p;//p是指向此树位置的 
}tr[555555]; 

long long cnt,root,x,y,z;

long long get(long long p){
	tr[++cnt].val=rnd();
	tr[cnt].key=a[p];
	tr[cnt].p=p;
	return cnt;
}

void split(long long p,long long key,long long &x,long long &y){
	if(p==0){
		x=y=0;
	}else if(key>=tr[p].key ){
		x=p;
		split(tr[p].r,key,tr[p].r,y);
	}else{
		y=p;
		split(tr[p].l,key,x,tr[p].l);
	}
	
}

long long merge(long long x,long long y){//x<y
	if(!x||!y){
		return x+y;
	}else if(tr[x].val>tr[y].val ){
		tr[x].r=merge(tr[x].r,y);
		return x;
	}else{
		tr[y].l=merge(x,tr[y].l );
		return y;
	}
}

void instert(long long p){
	split(root,a[p],x,z);
//	cout<<x<<y<<z<<endl;
	split(x,a[p]-1,x,y);
	root=merge(merge(x,get(p)),z);
//		for(int i=1;i<=5;i++){
//			cout<<tr[i].key<<" "<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].p<<" "<<a[tr[i].p]<<endl;
//		}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	a[1]=1;
//	a[2]=2;
//	a[3]=1;
//	instert(0);
//	instert(1);
//	instert(2);
//	instert(3);
	n=read();
	k=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		a[i]^=a[i-1];
	}
	instert(0);
	for(long long i=1;i<=n;i++){
		dp[i]=dp[i-1];
		split(root,(k^a[i]),x,z);
		split(x,(k^a[i])-1,x,y);
//		cout<<tr[y].p<<endl;
		if(y){
			dp[i]=max(dp[i],dp[tr[y].p]+1);
		}
		root=merge(merge(x,y),z);
		instert(i);
	} 
	cout<<dp[n];
	return 0;
}
