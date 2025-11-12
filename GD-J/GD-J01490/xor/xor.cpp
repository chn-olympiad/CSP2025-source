#include<bits/stdc++.h>
using namespace std;
int f1[500100],f2[500100],k,n;
int a[500100],ansa[500100],ok;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ansa[i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=ok+1;j<=i;j++){
			f2[j]=f1[j];
			f2[j]^=a[i];
			if(f2[j]==k){
				ok=j;
				ansa[i]=max(ansa[i],j);
			}
			f1[j]=f2[j];
		}
	}
	int now=0,ans;
	for(int i=1;i<=n;i++){
		if(ansa[i]!=-1){
			if(ansa[i]>now){
				ans++;
				now=i;
			}
		}
	}
	cout<<ans;
	return 0;
} 
