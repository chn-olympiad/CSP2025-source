#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		int zs=n*3;
		int a[zs];
		for(int i=1;i<=n*3;i++){
			cin>>a[i];
		}
		for(int j=1;j<=n*3;j++){
			if(j%3==0&&j!=1){
				int max=0;
				if(a[j]>max){
					max=a[j];
					if(a[j-1]>max){
						max=a[j-1];
						if(a[j-2]>max){
							max=a[j-2];
						}
					}
					cout<<max<<" ";
					ans=max+ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
