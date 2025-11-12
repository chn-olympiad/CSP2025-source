#include<bits/stdc++.h>
using namespace std;
int t,n[6],a[5][100005],ma[6],c[6]={1,1,1,1,1,1},cnt,w,b;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i][j]>>w>>w;
		}
	}
	for(int i=1;i<=t;i++){
		for(int x=1;x<=n[i]/2;x++){
			for(int j=1;j<=n[i];j++){
				cnt=max(a[i][j],cnt);
			}
			for(int j=1;j<=n[i];j++){
				if(cnt==a[i][j]){
					a[i][j]=-1;
					b=1;
				}
				if(b==1){
					j=n[i]+1;
					b=0;
				}
			}
			ma[i]+=cnt;
			cnt=0;
		}	
		
	}
	for(int i=1;i<=t;i++){
		cout<<ma[i]<<endl;
	}
	return 0;
}
//score:5
