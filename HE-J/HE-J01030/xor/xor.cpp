#include<bits/stdc++.h>
using namespace std;
int n,k,sum,ans;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=a[i];
		for(int j=i;j<=n;j++){
			sum=sum&+a[j];
			cout<<sum<<" ";
			if(sum==k){
				ans++;
			}
		}cout<<endl;      
	}
	cout<<ans<<endl;
	cout<<(0&+3);
	return 0;
}
