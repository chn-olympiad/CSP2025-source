#include <bits/stdc++.h>
using namespace std;
int t;
struct w{
	int x,y,z;
	int c1,c2,c3,q1,q2,q3;
};
bool cmp(w e,w d){
	if(e.c1!=d.c1){
		return e.c1>d.c1;

	}
	else{
		if(e.x!=d.x){
			return e.x>d.x;
		}
		else {
			if(e.c2!=d.c2){
				return e.c2>d.c2;

			}
			else{
				if(e.y!=d.y){
					return e.y>d.y;
				}
				else {
					if(e.c3!=d.c3){
						return e.c3>d.c3;
					}
					else{

						if(e.z!=d.z){
							return e.z>d.z;
						}
					}
				}
			}
		}
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){


		int n,ans=0;
		cin>>n;
		//int a[n+2][3];
		int z=n/2;
		w a[n+2];
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].c1=abs(a[i].x-a[i].y)+abs(a[i].x-a[i].z);
			a[i].c2=abs(a[i].y-a[i].x)+abs(a[i].y-a[i].z);
			a[i].c3=abs(a[i].z-a[i].y)+abs(a[i].z-a[i].x);
			if(a[i].x>=a[i].y &&a[i].x>=a[i].z){
				a[i].q1=1;
				if(a[i].y>=a[i].z){
					a[i].q2=2;
					a[i].q3=3;
				}
				else{
					a[i].q2=3;
					a[i].q3=2;
				}

			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].q1=2;
				if(a[i].x>=a[i].z){
					a[i].q2=1;
					a[i].q3=3;
				}
				else{
					a[i].q2=3;
					a[i].q3=1;
				}
				/*a[i].c1=abs(a[i].x-a[i].y)+abs(a[i].x-a[i].z);
				a[i].c2=abs(a[i].y-a[i].x)+abs(a[i].y-a[i].z);
				a[i].c3=abs(a[i].z-a[i].y)+abs(a[i].z-a[i].x);*/
			}
			else {
				a[i].q1=3;
				if(a[i].x>=a[i].y){
					a[i].q2=1;
					a[i].q3=2;
				}
				else{
					a[i].q2=2;
					a[i].q3=1;
				}
				/*a[i].c1=abs(a[i].x-a[i].y)+abs(a[i].x-a[i].z);
				a[i].c2=abs(a[i].y-a[i].x)+abs(a[i].y-a[i].z);
				a[i].c3=abs(a[i].z-a[i].y)+abs(a[i].z-a[i].x);*/
			}
		}
		sort(a+1,a+n+1,cmp);
		//cout<<a[1].c1;
		//cout<<a[2].c1;
		//int c=1;
		int z1=0;
		int z2=0;
		int z3=0;
		for(int i=1;i<=n;i++){
			if(a[i].q1==1){
				if(z1<z){
					z1++;
					ans+=a[i].x;
					//cout<<ans<<endl;
					continue;
				}
				else {
					if(a[i].q2==2){
						if(z2<z){
							z2++;
							ans+=a[i].y;
							//cout<<ans<<endl;
							continue;

						}
						//else {
							//if(a[i].q3==3){
						else if(z3<z){
							z3++;
							ans+=a[i].z;
							//cout<<ans<<endl;
							continue;
						}
							//}
						//}
					}
					else{
						if(a[i].q2==3){
							if(z3<z){
								z3++;
								ans+=a[i].z;
								//cout<<ans<<endl;
								continue;
							}
							else if(z2<z){
								z2++;
								ans+=a[i].y;
								//cout<<ans<<endl;
								continue;
							}
						}
					}
				}
			}



			else if(a[i].q1==2){
				if(z2<z){
					z2++;
					ans+=a[i].y;
					//cout<<ans<<endl;
					continue;
				}
				else{
					if(a[i].q2==1){
						if(z1<z){
							z1++;
							ans+=a[i].x;
							//cout<<ans<<endl;
							continue;
						}
						else if(z3<z){
							z3++;
							ans+=a[i].z;
							//cout<<ans<<endl;
							continue;
						}
					}
				}
				if(a[i].q2==3){
					if(z3<z){
						z3++;
						ans+=a[i].z;
						//cout<<ans<<endl;
						continue;
					}
					else if(z1<z){
						z1++;
						ans+=a[i].x;
						//cout<<ans<<endl;
						continue;
					}
				}
			}




			else{
				if(z3<z){
					z3++;
					ans+=a[i].z;
					//cout<<ans<<endl;
					continue;
				}
				else{
					if(a[i].q2==1){
						if(z1<z){
							z1++;
							ans+=a[i].x;
							//cout<<ans<<endl;
							continue;
						}
						else if(z2<z){
							z2++;
							ans+=a[i].y;
							//cout<<ans<<endl;
							continue;
						}
					}
				}
					if(a[i].q2==2){
						if(z2<z){
							z2++;
							ans+=a[i].y;
							//cout<<ans<<endl;
							continue;
						}
						else if(z1<z){
							z1++;
							ans+=a[i].x;
							//cout<<ans<<endl;
							continue;
						}
					}
				}
			}
			cout<<ans<<endl;



		}








	return 0;
}
