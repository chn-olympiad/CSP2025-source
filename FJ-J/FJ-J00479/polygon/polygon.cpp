#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(j-i<2){
				continue;
			}
			int len=0;
			for(int k=i;k<=j;k++){
				len=len+a[k];
			}
			if(len>a[j]*2){
				ans++;
				ans=ans+n-j;
				/*for(int k=i;k<=j;k++){
					cout<<a[k]<<" ";
				}*/
				/*cout<<endl;*/
			}
			
		}
	}
	cout<<ans;
	return 0;
}
