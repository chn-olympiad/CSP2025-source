#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans=0,s,maxn=-1,z=0,zj=0,k=1,c[5050],cnt;
bool b[5050];
void dfs(int g){
	if(n==g){
		if(k>3){
			maxn=-1;
			for(int i=1;i<k;i++){
				z+=c[i];
				maxn=max(maxn,c[i]);
				}
			if(z>2*maxn){
				for(int i=1;i<k;i++){
					cout<<c[i]<<" ";
				}
				cout<<endl;
				ans++;
			}
			return;
		}		
	}
	for(int i=g;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			c[k++]=a[i];
			dfs(g+1);
			b[i]=0;
			memset(c,0,sizeof(c));
			k=0;
		}
	}
	return;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		maxn=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>2*maxn){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}else{
		dfs(1);
		cout<<ans+2;
	}
	return 0;
} 