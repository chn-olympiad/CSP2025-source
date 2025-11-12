//GZ-S00194 遵义航天高级中学 徐浩威 
#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		int n;
		cin>>n;
		int a=0,b=0,d=0;
		int r[100005][3];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>r[i][j];
		}
		for(int i=1;i<=n;i++){
				if(r[i][1]>=r[i][2]&&r[i][1]>=r[i][3]){
					a+=r[i][1];
				}
				else if(r[i][2]>=r[i][1]&&r[i][2]>=r[i][3]){
					b+=r[i][2];
				}
				else if(r[i][3]>=r[i][1]&&r[i][3]>=r[i][2]){
					d+=r[i][3];
				}		
		}
		int ans=a+b+d;
		cout<<ans<<'\n';
		t--;
	}
	return 0;
}

