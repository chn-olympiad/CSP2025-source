#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int canel[(int)1e5+10];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		long long ans = 0;
		int a,b,c;
		for(int i=1;i<=n;i+=1){
			int x,y,z;
//			int x1,y1,z1;
			cin>>x>>y>>z;
//			if(x>y and y>z){
//				x1 = x,y1 = y,z1 = z;
//			}
//			else if(x>z and z>y){
//				x1 = x,y1 = z,z1 = y;
//			}
//			else if(y>x and x>z){
//				x1 = y,y1 = x,z1 = z;
//			}
//			else if(y>z and z>x){
//				x1 = y,y1 = z,z1 = x;
//			}
//			else if(z>x and z>y){
//				x1 = z,y1 = x,z1 = y;
//			}
//			else if(z>y and y>x){
//				x1 = z,y1 = y,z1 = x;
//			}
			canel[i] = x;
		}
		sort(canel+1,canel+1+n);
		for(int i=1;i<=n/2;i+=1){
			ans+=canel[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}
