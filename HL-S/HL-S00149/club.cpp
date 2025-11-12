#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int cnt;
int sum;
int a[100001];
int b[10000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int siluing=1;
	for(int i = siluing;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>a[i]>>b[i];
			cin>>a[i]>>b[i];
			cin>>a[i]>>b[i];
		}
		cnt=a[i]+b[i+2];
		if(a[i]>=t/2){
			break;
		}
		ans=a[i]+b[i+2]+siluing;
	}
	
	for(int i =siluing;i<=n;i++){
		ans++;
		for(int j = siluing;j<=n;j++){
			for(int k= siluing;k<=n;k++){
				cnt++;
			}
		}
		sum=cnt-ans-siluing;
	}
	cout<<cnt<<endl;
	cout<<ans<<endl;
	cout<<sum<<endl;
	return 0;
}