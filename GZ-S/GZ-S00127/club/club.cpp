//GZ-S00127，安顺市实验学校,孔思齐
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,sum,maxj;
int club[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>club[i][j];
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>club[i][j];
				maxj=club[i][1];
				if (maxj<club[i][j])
					maxj=club[i][j];
			}
			cout<<maxj<<endl;
			sum+=maxj;
		}
		cout<<sum<<endl;
	}
	return 0;
}
