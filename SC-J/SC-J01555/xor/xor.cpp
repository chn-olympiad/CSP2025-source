#include<bits/stdc++.h>
using namespace std;

int n,k,a[200001],b[200001],c[1000001][2],t,mx=-1,aaa=0;
int yh(int a,int b){
	int x,mi=1;
	bool aa[21],bb[21],cc[21];
	for(int i=1;i<=20;i++){
		aa[i]=bb[i]=cc[i]=0;
	}
	int i=20;
	while(a!=0){
		aa[i]=a&1;
		a=a>>1;
		i--;
	}
	i=20;
	while(b!=0){
		bb[i]=b&1;
		b=b>>1;
		i--;
	}
	for(i=1;i<=20;i++){
		cc[i]=aa[i]!=bb[i];
	}
	for(i=20;i>=1;i--){
		x+=mi*cc[i];
		mi*=2;
	}
	return x;
}
void dfs(int x,int y,int ans){
	mx=max(mx,ans);
	if(x==t+1) return;
	if(c[x][0]>y){
		dfs(x+1,max(y,c[x][1]),ans+1);
	}
	dfs(x+1,y,ans+1);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k>>a[1];
    b[1]=a[1];
    if(a[1]==1) aaa++;
    for(int i=2;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==1) aaa++;
    	b[i]=yh(b[i-1],a[i]);
	}
	if(aaa==n){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(b[j],b[j-i])==k){
				c[++t][0]=j-i+1;
				c[t][1]=j;
			}
		} 
	}
	dfs(1,0,0);
	cout<<mx<<endl;
    return 0;
}