#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		memset(b,0,sizeof(b));
		b[i]=a[i];
		for(int j=i+1;j<=n-1;j++){
			b[j]=a[j];
			for(int k=j+1;k<=n;k++){
				b[k]=a[k];
				sort(b+i,b+k+1,cmp);
				int num=0;
				for(int l=i;l<=k;l++) num+=b[l];
				if(num>b[i]*2){
					ans++;
				}
			}
		}
	}cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
