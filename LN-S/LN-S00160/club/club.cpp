#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,z,cnt=0;
	cin>>t;
	for(z=1;z<=t;z++){
		cin>>n;
		int ans[n][4];
		int a[n];
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>ans[i][1]>>ans[i][2]>>ans[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(ans[i][j]>=mp[i]){
					mp[i]=ans[i][j];
					a[i]=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i]==j and a[j]<=n/2) cnt+=mp[i];
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}


