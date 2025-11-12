//GZ-S00127，安顺市实验学校,孔思齐
#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005],n;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>mp[i][j];
	
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (mp[i][j]>mp[i][k]+mp[k][j])
					mp[i][j]=mp[i][k]+mp[k][j];
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<mp[i][j];
		}
	}
	return 0;
}
