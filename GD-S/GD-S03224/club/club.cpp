#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,num[4],a[N][4],b[N],ans; 
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a)); 
		memset(b,0,sizeof(b)); 
		memset(num,0,sizeof(num)); 
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				if(num[1]+1<=n/2){
					num[1]++;
					ans+=a[i][1];
					b[i]=1;
				}
				else{
					for(int j=1;j<i;j++){
						if(b[j]!=1) continue;
						int maxi,maxj,ii,jj;
						if(a[i][2]>=a[i][3]){
							maxi=a[i][2];
							ii=2;
						}
						else {
							maxi=a[i][3];
							ii=3;
						}
						if(a[j][2]>=a[j][3]){
							maxj=a[j][2];
							jj=2;
						}
						else {
							maxj=a[j][3];
							jj=3;
						}
						if(a[i][1]+maxj>=a[j][1]+maxi){
							ans=ans-a[j][1]+a[j][jj]+a[i][1];
							b[i]=1;
							b[j]=jj;
							a[j][1]=-1;
							num[jj]++;
							break; 
						}
						else{
							ans=ans+a[i][ii];
							b[i]=ii;
							num[ii]++;
							break;
						}
					}
				}
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				if(num[2]+1<=n/2){
					num[2]++;
					ans+=a[i][2];
					b[i]=2;
				}
				else{
					for(int j=1;j<i;j++){
						if(b[j]!=2) continue;
						int maxi,maxj,ii,jj;
						if(a[i][1]>=a[i][3]){
							maxi=a[i][1];
							ii=1;
						}
						else {
							maxi=a[i][3];
							ii=3;
						}
						if(a[j][1]>=a[j][3]){
							maxj=a[j][1];
							jj=1;
						}
						else {
							maxj=a[j][3];
							jj=3;
						}
						if(a[i][2]+maxj>=a[j][2]+maxi){
							ans=ans-a[j][2]+a[j][jj]+a[i][2];
							b[i]=1;
							b[j]=jj;
							a[j][2]=-1;
							num[jj]++;
							break;
						}
						else{
							ans=ans+a[i][ii];
							b[i]=ii;
							num[ii]++;
							break;
						}
					}
				}
			}
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				if(num[3]+1<=n/2){
					num[3]++;
					ans+=a[i][3];
					b[i]=3;
				}
				else{
					for(int j=1;j<i;j++){
						if(b[j]!=3) continue;
						int maxi,maxj,ii,jj;
						if(a[i][1]>=a[i][2]){
							maxi=a[i][1];
							ii=1;
						}
						else {
							maxi=a[i][2];
							ii=2;
						}
						if(a[j][1]>=a[j][2]){
							maxj=a[j][1];
							jj=1;
						}
						else {
							maxj=a[j][2];
							jj=2;
						}
						if(a[i][3]+maxj>=a[j][3]+maxi){
							ans=ans-a[j][3]+a[j][jj]+a[i][3];
							b[i]=3;
							b[j]=jj;
							a[j][3]=-1;
							num[jj]++;
							break;
						}
						else{
							ans=ans+a[i][ii];
							b[i]=ii;
							num[ii]++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
