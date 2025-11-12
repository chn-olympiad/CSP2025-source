#include<bits/stdc++.h>
using namespace std;
int t,n,cl1,cl2,cl3,cl[200001][4],flag,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		cl1=0;
		cl2=0;
		cl3=0;
		flag=0;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>cl[i][j];
			if(flag==1){
				cl1++;
				ans+=cl[i][1];
			}else if(flag==2){
				
			}else if(flag==3){
				
			}else{
				if(cl1>n/2){
					if(cl2>n/2){
						cl3++;
						ans+=cl[i][3];
						flag=3;
					}else{
						if(cl3>n/2){
							cl2++;
							ans+=cl[i][2];
							flag=2;
						}else{
							if(cl[i][2]>cl[i][3]){
								cl2++;
								ans+=cl[i][2];
							}else{
								cl3++;
								ans+=cl[i][3];
							}
						}
					}
				}else if(cl2>n/2){
					if(cl3>n/2){
						cl1++;
						ans+=cl[i][1];
						flag=1;
					}else{
						if(cl[i][1]>cl[i][3]){
							cl1++;
							ans+=cl[i][1];
						}else{
							cl3++;
							ans+=cl[i][3];
						}
					}
				}else if(cl3>n/2){
					if(cl[i][1]>cl[i][2]){
						cl1++;
						ans+=cl[i][1];
					}else{
						cl2++;
						ans+=cl[i][2];
					}
				}else{
					if(cl[i][1]>cl[i][2]&&cl[i][1]>cl[i][3]){
						cl1++;
						ans+=cl[i][1];
					}else if(cl[i][2]>cl[i][1]&&cl[i][2]>cl[i][3]){
						cl2++;
						ans+=cl[i][2];
					}else{
						cl3++;
						ans+=cl[i][3];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
