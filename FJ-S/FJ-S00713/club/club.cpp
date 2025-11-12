#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int cy[100010];
int t,n,ans,on,tw,th,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++){
		ans = 0;
		on = 0;
		tw = 0;
		th = 0;
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+n+1);
		for(int j = n;j>=1;j--){
			if(on<=n/2){
				ans+=a[j];
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

