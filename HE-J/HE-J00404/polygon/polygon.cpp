#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5010],b[5010],n,cnt=0,k;
bool f[5010];
bool pd(int b[],int m){
	int maxn=-2147483648,sum=0;
	for(int i=1;i<=m;i++){
		maxn=max(maxn,a[b[i]]);
		sum+=a[b[i]];
	}
	return sum>2*maxn;
}
void dg(int c,int m){
	if(c>=m){
		if(pd(b,m)) cnt++;
		return;
	}
	for(b[c]=1;b[c]<=k;b[c]++){
		if(f[b[c]]) continue;
		f[b[c]]=true;
		k--;
		dg(c+1,m);
		k++;
		f[b[c]]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		k=n;
		dg(1,i);
		memset(b,0,sizeof(b));
		memset(f,false,sizeof(f));
	}
	cout<<cnt-5;
	return 0;
}
