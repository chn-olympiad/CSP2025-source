#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool ans[5010];
int ans1[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,sum = 0,sum1 = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sum1+=a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	} 
	if(n==3){
		if((a[1]+a[2]+a[3])>a[3]*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i = 1;i<=n;i++){
		ans[a[i]] = 1;
		for(int j = 1;j<=i*2;j++){
			if(ans[j]){
				ans[j+a[i]] = 1;
//				cout<<j+a[i]<<endl;
				ans1[j+a[i]]=ans1[j]+1;
			}
		}
	}
//	for(int i = 1;i<=25;i++)cout<<ans1[i];
	for(int i = n;i>=1;i--){
		for(int j = 1;j<=i*2;j++){
			if(ans[j+2*a[i]]&&ans1[j+2*a[i]]>=3){
//				cout<<j+a[i]*2<<endl; 
				sum++;
			}
		}
	} 
	cout<<sum;
	return 0;
}
