#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int t,t1,a[3]={0},ans=0;
		cin>>t;
		t1=t/2;
		int x[10000][3]={0},y[100000][3]={0};
		for(int i=1;i<=t;i++){
			for(int j=1;j<=3;j++){
				cin>>x[i][j];
			}
		}
		for(int i=1;i<=t;i++){
					ans=ans+max(x[i][1],max(x[i][2],x[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
} 
