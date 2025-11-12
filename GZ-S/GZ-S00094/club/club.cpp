//GZ-S00094 贵阳市观山湖区普瑞学校 吴雨泽 
#include<bits/stdc++.h>
using namespace std;
int t,n,ans;int a[100005][5];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int s[5]={0,0,0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		//cout<<"\n";
		int k=n/2;
		for(int i=1;i<=n;i++){
			int mx=0,l;
			if(s[1]<k&&s[2]<k&&s[3]<k){
				for(int j=1;j<=3;j++){
					mx=max(a[i][j],mx);
				//	cout<<mx<<" ";
				}for(int u=1;u<=3;u++) if(a[i][u]==mx) s[u]++;
				ans+=mx;
				//cout<<"\n"<<ans<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

