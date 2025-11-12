#include<bits/stdc++.h>
using namespace std;
int t,n,cnt;
int mp[100005][5],ma[100005],d[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(ma,0,sizeof(ma));
		memset(d,0,sizeof(d));
		cnt=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>mp[j][k];
			}
			ma[j]=max(max(mp[j][1],mp[j][2]),mp[j][3]);
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
			    if(mp[j][k]==ma[j]){
			    	if(d[k]<=n/2){
			    	   cnt+=ma[j];
			    	   d[k]++;
					}else if(k==1){
						if(mp[j][2]>mp[j][3]){
						  cnt+=mp[j][2];
					      d[2]++;
						}else{
						  cnt+=mp[j][3];
					      d[3]++;
						}
					}else if(k==2){
						if(mp[j][1]>mp[j][3]){
						  cnt+=mp[j][1];
					      d[1]++;
						}else{
						  cnt+=mp[j][3];
						  d[3]++;
						}
					}else {
						if(mp[j][1]>mp[j][2]){
							cnt+=mp[j][1];
							d[1]++;
						}else{
							cnt+=mp[j][2];
							d[2]++;
						}
					}
				}
//			    if(j>1&&mp[j][1]==0&&mp[j][2]==0||mp[j][1]==0&&mp[j][3]==0||mp[j][2]==0&&mp[j][3]==0){
//	                      if(ma[j]>ma[j-1]-min(max(mp[j-1][1],mp[j-1][2]),max(mp[j-1][2],mp[j-1][3]))){
//	                         cnt-=ma[j];
//	                         cnt+=min(max(mp[j-1][1],mp[j-1][2]),max(mp[j-1][2],mp[j-1][3]));
//                          }
//                }
//	
	
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}
