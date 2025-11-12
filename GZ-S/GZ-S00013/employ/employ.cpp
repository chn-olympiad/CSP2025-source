//GZ-S00013 贵州省黔西第一中学 代毅承 
#include<bits/stdc++.h>
using namespace std;
int a[505],b[505],n,m,num=0,jl[505]={0},yes=0;
char s[505];
int jian(int i){
	b[i]=0;
	for(int j=0;j<n;j++){
		if(j!=i){
			b[j]--;
		}
	}
}
int hy(){
	memset(jl,0,505);
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
}
int xh(int x,int t){
	if(s[t]=='0'){
		jian(n+2);
	}
	if(num>=m){
		yes++;
	}
	jl[x]=1;
	for(int i=0;i<n;i++){
		if(i!=x && jl[i]==0 && b[i]>=0){
			num++;
			if(!(b[i]<0)){
				xh(i,t+1);
			}
			if(x>n && i>=n)	{
				return 0;
			}				
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>a[i];
		b[i]=a[i];
	}	
	for(int i=0;i<n;i++){	
	for(int j=0;j<n;j++){
		num=0;
		xh(j,1);
		hy();
	}			
	}
	int abb=num%998244353;
	cout<<abb;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
