#include<bits/stdc++.h>
using namespace std;
#define long long int
int arr[5005],b[5005];
int c[20] = {1,2,4,8,16,32,64,128,256,512,1024,2028,5056};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		b[i] = b[i-1]+arr[i];
	}
	sort(arr+1,arr+1+n);
	int ans = 0;
	for(int i = 3;i<=n;i++){
		int x = b[i]-2*arr[i];
		if(x<=0){
			continue;
		}else if(x==1){
			ans++;
		}else{
			ans++;
			int cnt1 = 0;
			for(int i = 1;i<=n;i++){
				if(b[i]>x){
					cnt1  =i-1;
					break;
				}
			}
			if(cnt1!=0){
				ans+=c[cnt1];
			}
			for(int i = cnt1+2;i<n;i++){
				if(arr[i]<=x){
					ans++;
				}else{
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
