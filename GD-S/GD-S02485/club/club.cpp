#include<bits/stdc++.h>
using namespace std;
int a[4][200020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//≥ı ºªØ
		for(int i=1;i<=n;i++){
			fill(a[i]+1,a[i]+4,0);
		} 
		// ‰»Î 
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int x[4];
		x[1]=x[2]=x[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int max_id=0;
			int max_s=0;
			for(int j=1;j<=3;j++){
				if(x[j]+1<=n/2&&max_s<a[i][j]){
					max_s=a[i][j];
					max_id=j;
				}
			}
			x[max_id]++;
			ans+=max_s;
		}
		cout<<ans<<endl;
	}
	return 0;
}

