#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int p[n][3];
		int c[3][n];
		for(int j=0;j<3;j++){
			for(int m=0;m<n;m++){
				c[j][m]=0;
			}
		} 
		for(int j=0;j<n;j++){
			for(int m=0;m<3;m++){
				cin>>p[j][m];
			}
		}
		for(int j=0;j<n;j++){
			int in=0,mx=0;
			for(int m=0;m<3;m++){
				if(p[j][m]>=mx){
					mx=p[j][m];
					in=m;
				}
			}
			c[in][j]=1;
		}
		int larger[3]={0};
		for(int j=0;j<3;j++){
			int count=0;
			for(int m=0;m<n;m++){
				if(c[j][m]==1){
					count++;
				}
			}
			if(count>n/2){
				larger[j]=1;
			}
		}
		if(larger[0]==0&&larger[1]==0&&larger[2]==0){
			int ans=0;
			for(int j=0;j<3;j++){
				for(int m=0;m<n;m++){
					if(c[j][m]==1){
						ans+=p[m][j];
					}
				}
			}
			cout<<ans;
		}else{
			while(1){
				if(larger[0]==1){
					int min=2147483647,person=0;
					for(int m=0;m<n;m++){
						if(c[0][m]==1){
							if(p[m][0]<min){
								min=p[m][0];
								person=m;
							}
						}
					}
					c[0][person]=0;
					int mx=-1,mn=2147483647,mxin=0,mnin=0,second=0;
					for(int j=0;j<3;j++){
						if(p[person][j]<mn){
							mn=p[person][j];
							mnin=j;
						}
						if(p[person][j]>mx){
							mx=p[person][j];
							mxin=j;
						}
					}
					for(int m=0;m<3;m++){
						if(m!=mxin&&m!=mnin){
							second=m;
							break;
						}
					}
					c[second][person]=1;
					for(int j=0;j<3;j++){
						int count=0;
						for(int m=0;m<n;m++){
							if(c[j][m]==1){
								count++;
							}
						}
						if(count>n/2){
							larger[j]=1;
						}
					}
				}else if(larger[1]==1){
					int min=2147483647,person=0;
					for(int m=0;m<n;m++){
						if(c[1][m]==1){
							if(p[m][1]<min){
								min=p[m][1];
								person=m;
							}
						}
					}
					c[1][person]=0;
					int mx=-1,mn=2147483647,mxin=0,mnin=0,second=0;
					for(int j=0;j<3;j++){
						if(p[person][j]<mn){
							mn=p[person][j];
							mnin=j;
						}
						if(p[person][j]>mx){
							mx=p[person][j];
							mxin=j;
						}
					}
					for(int m=0;m<3;m++){
						if(m!=mxin&&m!=mnin){
							second=m;
							break;
						}
					}
					c[second][person]=1;
					for(int j=0;j<3;j++){
						int count=0;
						for(int m=0;m<n;m++){
							if(c[j][m]==1){
								count++;
							}
						}
						if(count>n/2){
							larger[j]=1;
						}
					}
					if(larger[0]==0&&larger[1]==0&&larger[2]==0){
						break;
					}
				}else{
					int min=2147483647,person=0;
					for(int m=0;m<n;m++){
						if(c[2][m]==1){
							if(p[m][2]<min){
								min=p[m][2];
								person=m;
							}
						}
					}
					c[2][person]=0;
					int mx=-1,mn=2147483647,mxin=0,mnin=0,second=0;
					for(int j=0;j<3;j++){
						if(p[person][j]<mn){
							mn=p[person][j];
							mnin=j;
						}
						if(p[person][j]>mx){
							mx=p[person][j];
							mxin=j;
						}
					}
					for(int m=0;m<3;m++){
						if(m!=mxin&&m!=mnin){
							second=m;
							break;
						}
					}
					c[second][person]=1;
				}
				for(int j=0;j<3;j++){
					larger[j]=0;
				}
				for(int j=0;j<3;j++){
					int count=0;
					for(int m=0;m<n;m++){
						if(c[j][m]==1){
							count++;
						}
					}
					if(count>n/2){
						larger[j]=1;
					}
				}
				if(larger[0]==0&&larger[1]==0&&larger[2]==0){
					break;
				}
			}
			int ans=0;
			for(int j=0;j<3;j++){
				for(int m=0;m<n;m++){
					if(c[j][m]==1){
						ans+=p[m][j];
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
} 
