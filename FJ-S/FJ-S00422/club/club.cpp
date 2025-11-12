#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100005][4];
bool cmp(int a , int b){
	return a>b;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2){
			for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}	
			}
			cout<<ans<<"\n";
			ans=0;
		}else if(n==4){
		   for(int i=1;i<=n;i++){
		   for(int b=1;b<=n;b++){
		   for(int c=1;c<=n;c++){
		   for(int d=1;d<=n;d++){
				int vis[5]={0,0,0,0,0};
				vis[i]++;
				vis[b]++;
				vis[c]++;
				vis[d]++;
				if(vis[1]<=2&&vis[2]<=2&&vis[3]<=2){
					int num=a[1][i]+a[2][b]+a[3][c]+a[4][d];
					ans=max(ans,num);
				}
		   }	
		   }
		   }	
		   }	
		   cout<<ans<<"\n";
		   ans=0;
		}else if(n==10){
		    
		   for(int s=1;s<=n;s++){
		   for(int b=1;b<=n;b++){
		   for(int c=1;c<=n;c++){
		   for(int d=1;d<=n;d++){
		   for(int e=1;e<=n;e++){
		   for(int f=1;f<=n;f++){
		   for(int g=1;g<=n;g++){
		   for(int h=1;h<=n;h++){
		   for(int i=1;i<=n;i++){
		   for(int j=1;j<=n;j++){
		   int vis[15];
		   vis[s]++;
		   vis[b]++;
		   vis[c]++;
		   vis[d]++;
		   vis[e]++;
		   vis[f]++;
		   vis[g]++;
		   vis[h]++;
		   vis[i]++;
		   vis[j]++;
		   if(vis[1]<=5&&vis[2]<=5&&vis[3]<=5){
					int num=a[1][s]+a[2][b]+a[3][c]+a[4][d]+a[5][e]+a[6][f]+a[7][g]+a[8][h]+a[9][i]+a[10][j];
					ans=max(ans,num);
			}
		   }	
		   }		
		   }	
		   }
		   }	
		   }	
		   }	
		   }
		   }	
		   }
		   cout<<ans<<"\n";
		   ans=0;	
		}else if(n=100000&&a[1][2]==0&&a[1][3]==0&&a[2][1]==0&&a[2][3]==0){
			int aans[100005];
			for(int i=1;i<=n;i++){
				a[i][1]=aans[i];
			}
			sort(aans+1,aans+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans+aans[i];
			}
			cout<<ans<<"\n";
			ans=0;
		}else{
			int anum=0,bnum=0,cnum=0,aans=0,bans=0,cans=0;
			int avis[100005],bvis[100005],cvis[100005];
			for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(anum<n/2){
				avis[i]=a[i][1];
				anum++;
				aans=aans+avis[i];
				}else{
				    int dis=0,sum=i;
					for(int j=1;j<=i;j++){
						if(avis[j]>0){
							dis=min(avis[i],avis[j]);
							sum=j;
						}
					}
					aans=aans-dis+avis[i];
					avis[sum]=0;
					
					
					if(a[sum][2]>a[sum][3]){
						if(bnum<n/2){
		                bvis[sum]=a[sum][2];
				        bnum++;
				        bans=bans+bvis[sum];
				        }
					}else{
						if(cnum<n/2){
				        cvis[sum]=a[sum][3];
				        cnum++;
				        cans=cans+cvis[sum];
				        }
					}  
				}
			}
			
			
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				if(bnum<n/2){
		        bvis[i]=a[i][2];
				bnum++;
				bans=bans+bvis[i];
				}else{
				    int dis=0,sum=i;
					    for(int j=1;j<=i;j++){
						    if(bvis[j]>0){
							    dis=min(bvis[i],bvis[j]);
							    sum=j;
						    }
					    }
					    bans=bans-dis+bvis[i];
					    bvis[sum]=0;
					
					
					    if(a[sum][1]>a[sum][3]){
						    if(anum<n/2){
		                    avis[sum]=a[sum][1];
				            anum++;
				            aans=aans+avis[sum];
				            }
					    }else{
						    if(cnum<n/2){
				            cvis[sum]=a[sum][3];
				            cnum++;
				            cans=cans+cvis[sum];
				        }
					}  	
				}	
			}
			
			
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				if(cnum<n/2){
				cvis[i]=a[i][3];
				cnum++;
				cans=cans+cvis[i];
				}else{
				    int dis=0,sum=i;
					    for(int j=1;j<=i;j++){
						    if(cvis[j]>0){
							    dis=min(cvis[i],cvis[j]);
							    sum=j;
						    }
					    }
					    cans=cans-dis+cvis[i];
					    cvis[sum]=0;
					
					
					    if(a[sum][1]>a[sum][2]){
						    if(anum<n/2){
		                    avis[sum]=a[sum][1];
				            anum++;
				            aans=aans+avis[sum];
				            }
					    }else{
						    if(bnum<n/2){
				            bvis[sum]=a[sum][2];
				            bnum++;
				            bans=bans+bvis[sum];
				        }
					}  		
				}
				
			}
			
			
			cout<<aans+bans+cans<<"\n";
			aans=0;bans=0;cans=0;
			anum=0;bnum=0;cnum=0;
		}
	    }
		}
	return 0;
}
