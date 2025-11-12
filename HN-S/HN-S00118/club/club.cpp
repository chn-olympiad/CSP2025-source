#include<bits/stdc++.h>
using namespace std;
bool cmp(int x1,int x2){
	if(x1>x2)return 1;
	return 0;
}
int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int nm;
	cin>>nm;
	while(nm--) {
		int n,ans=0;
		vector<int>a1;
		for(int i=0; i<3; i++)a1.push_back(0);
		cin>>n;
		int te=n/2;
		cout<<te<<endl;
		int a[100001][5];
		bool pianfen=1;
		vector<int>p;
		for(int i=0; i<n; i++) {
			int max1=0,max2=0;
			vector<int>tem;
			for(int j=0; j<3; j++) {
				cin>>a[i][j];
				
				if(max1<a[i][j]) {
					max1=a[i][j];
					max2=j;
				}if(j>0 and pianfen){
					if(a[i][j]!=0)pianfen=0;
				}
				tem.push_back(a[i][j]);
			}
			if(pianfen){
				p.push_back(a[i][0]);
			}
			if(a1[max2]<te) {
				ans+=max1;
				a1[max2]++;
			} else {
				bool flag=1;int ta=3; 
				while(flag and ta--) {
					a[i][max2]=0;
					for(int j=0; j<3; j++) {
						if(max1<a[i][j]) {
							max1=a[i][j];
							max2=j;
						}
					}
					if(a1[max2]<te) {
						ans+=max1;
						a1[max2]++;
						flag=0;
					}
				}
			}
		}
		if(pianfen){
			int ans2=0;
			sort(p.begin(),p.end(),cmp);
			for(int i=0;i<n/2;i++){
				ans2+=p[i];
			}cout<<ans2<<endl;
		}
		else cout<<ans<<endl;
	}return 0;
} 
