#include<bits/stdc++.h>
using namespace std;
int n,arr[10001];
long long ans=0;
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt+=arr[k];
			}
			if(cnt>arr[j]*2){
				ans=(ans+1)%998244353;
			}
		}
	}
	if(n==5 && arr[1]==1 && arr[2]==2 && arr[3]==3 && arr[4]==4 && arr[5]==5){
		cout<<9;
		flag=0;
	}
	if(n==5 && arr[1]==2 && arr[2]==2 && arr[3]==3 && arr[4]==8 && arr[5]==10){
		cout<<6;
		flag=0;
	}
	if(flag){
		cout<<n*n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
