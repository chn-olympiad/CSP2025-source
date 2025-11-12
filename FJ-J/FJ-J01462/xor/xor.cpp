#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
int f[500005];
int flag;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
//		cout<<b[i]<<' ';
	}
//	cout<<endl;
	for(int len=1;len<=n;len++){
		for(int j=1;j+len-1<=n;j++){
			flag=0;
			for(int k=j;k<=j+len-1;k++){
				if(f[k]==1){
					flag=1;
					break;
				}
			}
			if(flag==1){
				continue;
			} 
			if((b[j+len-1] xor b[j-1])==k){
				ans++;
//				cout<<j<<" "<<j+len-1<<' '<<b[j-1]<<' '<<b[j+len-1]<<endl;
				for(int k=j;k<=j+len-1;k++) f[k]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

