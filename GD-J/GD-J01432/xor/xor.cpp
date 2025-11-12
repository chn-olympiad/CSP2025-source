#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500100],d[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(d,-1,sizeof(d));
		for(int j=i;j<=n;j++){
			if(d[j-1]==-1)d[j]=a[j];
			else if(d[j]!=-1){
				d[j]=(d[j-1] ^ a[j]);
			}
			if(d[j]==k){
				ans++;
				for(int k=i;k<=j;k++)d[k]=-1;
				for(int k=i;k<=j;k++)a[k]=-1;
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
