#include<bits/stdc++.h>
using namespace std;
int t;

struct node{
	int x,y,z,mx,cz;
}a[100005];

bool cmp(node u,node v){
	if(u.cz==v.cz){
		if(u.x==v.x){
	        if(u.y==v.y){
		    	return u.z>v.z;
	    	}
	    	else{
	    		return u.y>v.y;
	    	}
	    }
	    else{
	    	return u.x>v.x;
	    }
	}
	else{
		return u.cz>v.cz;
	}
}

int main(){

	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&t);
	
	while(t--){
		int ans=0;
		int n;
		scanf("%d",&n);
		int tt=n/2;
		int b[5];
		
		for(int i=1;i<=n;i++){
			
			cin>>a[i].x>>a[i].y>>a[i].z;
			
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				a[i].mx=1;
				if(a[i].y>=a[i].z){
					a[i].cz=a[i].x-a[i].y;
				}
				else{
					a[i].cz=a[i].x-a[i].z;
				}
				continue;
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				a[i].mx=2;
				if(a[i].x>=a[i].z){
					a[i].cz=a[i].y-a[i].x;
				}
				else{
					a[i].cz=a[i].y-a[i].z;
				}
				continue;
			}
			else if(a[i].z>a[i].x&&a[i].z>a[i].y){
				a[i].mx=3;
				if(a[i].y>=a[i].x){
					a[i].cz=a[i].z-a[i].y;
				}
				else{
					a[i].cz=a[i].z-a[i].x;
				}
				continue;
			}
			else if(a[i].x==a[i].y&&a[i].x==a[i].z){
				a[i].mx=0;
				
				continue;
			}
			else if(a[i].x==a[i].y){
				a[i].mx=4;
				a[i].cz=a[i].x-a[i].y;
			}
			else if(a[i].x==a[i].z){
				a[i].mx=5;
				a[i].cz=a[i].x-a[i].y;
			}
			else if(a[i].y==a[i].z){
				a[i].cz=a[i].y-a[i].x;
				a[i].mx=6;
			}
		}
		
		for(int i=1;i<=3;i++){
			b[i]=0;
		}
		
		
		sort(a+1,a+n+1,cmp);
		
//		for(int i=1;i<=n;i++){
//			cout<<a[i].id<<a[i].x<<a[i].y<<a[i].z<<a[i].mx<<endl;
//		}cout<<endl;
		
		for(int i=1;i<=n;i++){
			
			if(a[i].mx==1){
				if(b[1]<tt){
					//cout<<a[i].x<<"+";
					ans+=a[i].x;
				    b[1]++;
				    continue;
				}
				else{
					if(a[i].y>a[i].z){
						if(b[2]<tt){
							ans+=a[i].y;
							b[2]++;
							continue;
						}
						else{
							ans+=a[i].z;
							b[3]++;
							continue;
						}
					}
					else if(a[i].y<a[i].z){
						if(b[3]<tt){
							ans+=a[i].z;
							b[3]++;
							continue;
						}
						else{
							ans+=a[i].y;
							b[2]++;
							continue;
						}
					}
					else{
						if(b[2]<=b[3]){
							ans+=a[i].y;
							b[2]++;
							continue;
						}
						else{
							ans+=a[i].y;
							b[3]++;
							continue;
						}
					}
				}
			}
			
			else if(a[i].mx==2){
				if(b[2]<tt){
					//cout<<a[i].y<<"+";
					ans+=a[i].y;
				    b[2]++;
				    continue;
				}
				else{
					if(a[i].x>a[i].z){
						if(b[1]<tt){
							ans+=a[i].x;
							b[1]++;
							continue;
						}
						else{
							ans+=a[i].z;
							b[3]++;
							continue;
						}
					}
					else if(a[i].x<a[i].z){
						if(b[3]<tt){
							ans+=a[i].z;
							b[3]++;
							continue;
						}
						else{
							ans+=a[i].x;
							b[1]++;
							continue;
						}
					}
					else{
						if(b[1]<=b[3]){
							ans+=a[i].x;
							b[1]++;
							continue;
						}
						else{
							ans+=a[i].x;
							b[3]++;
							continue;
						}
					}
				}
			}
			
			else if(a[i].mx==3){
				//cout<<a[i].z<<"+";
				if(b[3]<tt){
					ans+=a[i].z;
				    b[3]++;
				    continue;
				}
				else{
					if(a[i].x>a[i].y){
						if(b[1]<tt){
							ans+=a[i].x;
							b[1]++;
							continue;
						}
						else{
							ans+=a[i].y;
							b[2]++;
							continue;
						}
					}
					else if(a[i].x<a[i].y){
						if(b[2]<tt){
							ans+=a[i].y;
							b[2]++;
							continue;
						}
						else{
							ans+=a[i].x;
							b[1]++;
							continue;
						}
					}
					else{
						if(b[1]<=b[2]){
							ans+=a[i].x;
							b[1]++;
							continue;
						}
						else{
							ans+=a[i].x;
							b[2]++;
							continue;
						}
					}
				}
			}
			
			else if(a[i].mx==0){
				ans+=a[i].x;
				if(b[1]<b[2]||b[1]<b[3]){
					b[1]++;
					continue;
				}
				if(b[2]<b[1]||b[2]<b[3]){
					b[2]++;
					continue;
				}
				else{
					b[3]++;
					continue;
				}
			}
			
			else if(a[i].mx==4){
				if(b[2]<tt||b[1]<tt){
					if(b[1]<b[2]){
					    ans+=a[i].x;
					    b[1]++;
					    continue;
					}
					else{
						ans+=a[i].x;
						b[2]++;
						continue;
					}
				}
				else{
					ans+=a[i].z;
					b[3]++;
					continue;
				}
			}
			
			else if(a[i].mx==5){
				if(b[3]<tt||b[1]<tt){
					if(b[1]<=b[3]){
					    ans+=a[i].x;
					    b[1]++;
					    continue;
					}
					else{
						ans+=a[i].x;
						b[3]++;
						continue;
					}
				}
				else{
					ans+=a[i].y;
					b[2]++;
					continue;
				}
			}
			
			else if(a[i].mx==6){
				if(b[2]<tt||b[3]<tt){
					if(b[3]<=b[2]){
					    ans+=a[i].z;
					    b[3]++;
					    continue;
					}
					else{
						ans+=a[i].z;
						b[2]++;
						continue;
					}
				}
				else{
					ans+=a[i].x;
					b[1]++;
					continue;
				}
			}
	    }
		//cout<<"=";
		printf("%d\n",ans);
	}
	
	return 0;
}