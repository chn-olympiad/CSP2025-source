#include<bits/stdc++.h>
using namespace std;
int a[10005][3];
int cnt[10005];
int num[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];				
			}
		}
		int ans=0;
		if(n=2){
			for(int i=0;i<n;i++){		
				memset(cnt,0,sizeof(cnt));
				for(int j=0;j<3;j++){
					cnt[i]=max(a[i][j],cnt[i]);
				}
				ans+=cnt[i];
			}
		}
		cout<<ans;
	}
	return 0;
}