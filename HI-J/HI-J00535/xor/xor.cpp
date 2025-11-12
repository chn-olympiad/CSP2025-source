#include<iostream>
using namespace std;
int a[500000],n,k,ma=0;
bool p[500000]={0};
int js(int b,int c){
	int bl=1,s=0;
	while(c>0||b>0){
		if(c%2!=b%2)s+=bl;
		c/=2;
		b/=2;
		bl*=2;
	}
	return s;
}
void dfs(int j,int l,int c){
	if(j<0||p[j])return ;
	if(l==k){
		ma++;
		p[c]=1;
		return ;
	}
	dfs(j-1,js(l,a[j-1]),c);
}
signed main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dfs(i,a[i],i);
	}
	cout<<ma;
	return 0;
} 
