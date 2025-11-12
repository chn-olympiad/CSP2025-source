#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,b[100001],sum=0,c=0,p=0,l=0;
	char a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			sum=sum+i;
		}
		cout<<sum%998244353;
		return 0;
	}
	for(int k=1;k<=n;k++){
   	 for(int i=1;i<=n;i++){
	  for(int t=1;t<=n;t++){
		c=a[t];
		if(c==48||b[t]==0){
			p++;
			for(int j=p;j<=m;j++){
				b[j]=b[j]-1;
			}
		}else{
			l++;
		}
		if(l==m){
			sum++;
		}
	  }
	  swap(b[k],b[i]);
     }
   }
   cout<<sum%998244353;
	return 0;
}
