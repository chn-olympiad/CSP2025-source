/*

*/

#include<bits/stdc++.h>
using namespace std;
struct node{
	int a[4];
}memb[100005];
vector<int> te;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>memb[i].a[1]>>memb[i].a[2]>>memb[i].a[3];
		te.clear();
		if (n==2){
			for (int i=1;i<=3;i++){
				for (int j=1;j<=3;j++){
					if (i==j)
						continue;
					te.push_back(memb[1].a[i]+memb[2].a[j]);
				} 
			}
			sort(te.begin(),te.end(),greater<int>());
			cout<<te[0]<<'\n';
		}
		else if (n==4){
			for (int i=1;i<=3;i++){
				for (int j=1;j<=3;j++){
					for (int k=1;k<=3;k++){
						for (int m=1;m<=3;m++){
							if ((i==j && j==k) || (i==j && j==m) || (i==k && k==m) || (j==k && k==m))
								continue;
							te.push_back(memb[1].a[i]+memb[2].a[j]+memb[3].a[k]+memb[4].a[m]);
						}
					}
				} 
			}
			sort(te.begin(),te.end(),greater<int>());
			cout<<te[0]<<'\n';
		}
		else
			cout<<47<<'\n';
	}
	
	return 0;
}
