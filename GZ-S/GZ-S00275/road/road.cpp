//GZ-S00275 贵阳市第十九中学 杨雅琪 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000005][3],b[15][10005];
int c[1000005];
int ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(j==2){
				ans+=a[i][j];
			}
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<m;i++){
		c[i]=a[i][2];
	}
	sort(c,c+m,cmp);
	if(k==0){
		ans-=c[0];
		cout<<ans<<endl;
		return 0;
	}
	else{
		sort(c,c+m);
		cout<<c[0]<<endl;
		return 0;
	}
}
