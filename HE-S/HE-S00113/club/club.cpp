#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t,num=0;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n;
		for(int i=0;i<=n-1;i++){
			cin>>a>>b>>c;
			int z1=max(max(a,b),c),z3=min(min(a,b),c),z2=a+b+c-z1-z3,ar=0,br=0,cr=0;
			bool f=true;
			if(z1==a && ar+1<=n/2 && f){
				num+=z1;
				ar++;
				f=false;
			}
			else if(z1==b && br+1<=n/2 && f){
				num+=z1;
				br++;
				f=false;
			}
			else if(z1==b && cr+1<=n/2 && f){
				num+=z1;
				cr++;
				f=false;
			}
			else if(f){
				if(z2==a && ar+1<=n/2 && f){
					num+=z2;
					ar++;
					f=false;
				}
				else if(z2==b && br+1<=n/2 && f){
					num+=z2;
					br++;
					f=false;
				}
				else if(z2==b && cr+1<=n/2 && f){
					num+=z2;
					cr++;
					f=false;
				}
				else if(f){
					if(z3==a && ar+1<=n/2 && f){
						num+=z3;
						ar++;
						f=false;
					}
					else if(z3==b && br+1<=n/2 && f){
						num+=z3;
						br++;
						f=false;
					}
					else if(z3==b && cr+1<=n/2 && f){
						num+=z3;
						cr++;
						f=false;
					}
				}
			}
		}
	}
	cout<<num;
	return 0;
}
