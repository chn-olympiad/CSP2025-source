#include<bits/stdc++.h>
using namespace std;
int a[100005],b[50001][2];
int n,k,bnum,ans=0;
void xo(int l,int r){
	int sum=a[l];
	for(int i=l;i<r;i++){
		sum|=a[i+1];
	}
	if(sum==k){
		b[++bnum][0]=l,b[bnum][1]=r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;  
	}
	if(flag) cout<<n;
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				xo(i,j);
			}
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=bnum;j++){
				if(b[j][1]==i&&a[b[j][0]]==0){
					for(int l=b[j][0];l<=b[j][1];l++){
						a[l]=1;
					}
					ans++;
				} 
			}
		}
		cout<<ans;
	}
	return 0;
}
