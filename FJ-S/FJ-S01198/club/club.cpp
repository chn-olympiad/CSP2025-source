#include<bits/stdc++.h>
using namespace std;
int c1=0,c2=0,c3=0,cnt=0,cnt1=0,cnt2=0,cnt3=0,v,t,n,a[100005][5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			v=max(a[i][1],max(a[i][2],a[i][3]));
			cnt+=v;
			if(v=a[i][1]){
				c1++;
			}
			if(v=a[i][2]){
				c2++;
			}
			if(v=a[i][3]){
				c3++;
			}
		}
		//if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			cout<<cnt<<endl;
			cnt=0;
		//}
	}	
	return 0;
}
				
