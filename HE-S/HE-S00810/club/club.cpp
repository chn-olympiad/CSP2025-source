#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,a[100005],b[100005],c[100005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		int max1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=n;z++){
					max1=max(max1,a[i]+b[j]+c[i]);
						
				}
			}
		}cout<<max1<<endl;
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
