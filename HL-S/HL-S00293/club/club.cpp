#include<bits/stdc++.h>
using namespace std;
struct c{
	int a1,a2,a3;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}	
	}
	cout<<n<<endl;
	while(t--){
		int x=a[0].a1,y=a[0].a2,z=a[0].a3;
		for(int i=0;i<n;i++){
			int x=a[0].a1,y=a[0].a2,z=a[0].a3;
			if(a[i].a1>a[i+1].a1){
			    x=a[i+1].a1;
			}if(a[i].a2>a[i+1].a2){
			 	y=a[i+1].a2;
			}if(a[i].a3>a[i+1].a3){
			 	z=a[i+1].a3;
			}
		}	
		if(x>=y&&x>=z){
		   if(y>=z){
		   	cout<<x+y;
		   	break;
		   }else if(z>=y){
		   	cout<<x+z;
		   	break;
		   }
		}else if(y>=x&&y>=z){
		   if(x>=z){
		   	cout<<x+y;
		   	break;
		   }else if(z>=x){
		   	cout<<y+z;
		   	break;
		   }
		}else if(z>=x&&z>=y){
		   if(x>=y){
		   	cout<<x+z;
		   	break;
		   }else if(y>=x){
		   	cout<<y+z;
		   	break;
		   }
		}
	}
	return 0;
}
