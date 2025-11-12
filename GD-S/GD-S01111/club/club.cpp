#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a[100005][4],f[4]={0};
		for(int j=1;j<=n;j++){
			for(int k=1;k<4;k++){
				cin>>a[j][k];
			}
		}
		int ans=0,c[100005]={0},q,w;
		for(int h=1;h<=n;h++){
			int max1=-1;	
			for(int j=1;j<=n;j++){
				for(int k=1;k<4;k++){
					if(max1<=a[j][k]&&!c[j]&&f[k]<n/2){
						max1=a[j][k];
						q=j;
						w=k;
					}
				}
			}
			ans+=max1;
			c[q]=1;
			f[w]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
