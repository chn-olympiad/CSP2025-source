#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,ans=INT_MAX,d[20],f[20],q,a[N],z[N];
bool flag=true;
int b[N][20];
int basic_search(int l,int s[N],int k){
	int cnt=0;
	for(int i=1;i<=l;i++){
		if(k==1){
			if(s[i]==1) cnt++;
		}
		if(k==0){
			if(s[i]==0) cnt++;
			else if(i!=l){
				++i;
				cnt++;
			}
		}
	}
	return cnt;
}
void two_transform(int x,int u){
	int c[20],m=0;
	if(x==0){
		for(int i=1;i<=20;i++) b[u][i]=0;
	}
	else{
		while(x>0){
			c[++m]=x%2;
			x/=2;
		}
		for(int i=1;i<=20-m;i++){
			b[u][i]=0;
		}
		for(int i=m,j=20-m+1;i>=1;i--,j++){
			b[u][j]=c[i];
		}	
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0 && a[i]!=1) flag=false;
	}
	if(flag){
		ans=basic_search(n,a,k);
		cout<<ans<<endl;
	}
	else{
		int tmp=k,v=0;
		while(tmp>0){
			d[++v]=tmp%2;
			tmp/=2;
		}
		for(int i=1;i<=20-v;i++) f[i]=0;
		for(int i=v,j=20-v+1;i>=1;i--,j++){
			f[j]=d[i];
		}
		for(int i=1;i<=n;i++){
			two_transform(a[i],i);
		}
		for(int i=1;i<=20;i++){
			for(int j=1;j<=n;j++){
				z[i]=b[j][i];
			}
			ans=min(ans,basic_search(20,z,f[i]))+1;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
