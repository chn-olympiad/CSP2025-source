#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,ans,a[maxn][6];
int c[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		for(int i=0;i<3;i++)c[i]=0;
		ans=0;
		cin >> n;
		for(int i=0;i<n;i++){
			int ind1=0;
			int ind2=0;
			for(int j=0;j<3;j++){
				cin >> a[i][j];
				if(a[i][j]>a[i][ind1]){
					ind2=ind1;
					ind1=j;
				}else if(a[i][j]>a[i][ind2])ind2=j;
			}
			if(ind1==ind2)ind2=(a[i][1]>=a[i][2]?1:2);
			a[i][3]=ind1;
			a[i][4]=ind2;
			a[i][5]=a[i][ind1]-a[i][ind2];
			c[ind1]++;
			ans+=a[i][ind1];
			if(c[ind1]>(n>>1)){
				int mj=INT_MAX,xj=-1;
				for(int j=0;j<i;j++){
					if(a[j][3]!=ind1)continue;
					if(a[i][5]<=a[j][5])continue;
					else{
						if(a[j][5]<mj)mj=a[j][5],xj=j;
					}
				}
				if(xj!=-1){
					ans-=a[xj][5];
					c[ind1]--;
					c[a[xj][4]]++;
					a[xj][3]=-1;
				}
				if(c[ind1]>(n>>1)){
					ans-=a[i][5];
					a[i][3]=-1;
					c[ind1]--;
					c[ind2]++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
//(^v^)=b
