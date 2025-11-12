#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int x,y,z;
	int max1=1,max2=2,max3=3;
	bool f=true;
}a[N];
struct ment{
	int cur;
	long long num;
}ans[5];
void check(int x,int y,int z,int j){
	if(x>=y&&y>=z){
		a[j].max1=1;
		a[j].max2=2;
		a[j].max3=3;
	}
	else if(y>=x&&x>=z){
		a[j].max1=2;
		a[j].max2=1;
		a[j].max3=3;	
	}else if(x>=z&&z>=y){
		a[j].max1=1;
		a[j].max2=3;
		a[j].max3=2;
	}else if(z>=x&&x>=y){
		a[j].max1=3;
		a[j].max2=1;
		a[j].max3=2;
	}else if(y>=z&&z>=x){
		a[j].max1=2;
		a[j].max2=3;
		a[j].max3=1;
	}else if(z>=y&&y>=z){
		a[j].max1=3;
		a[j].max2=2;
		a[j].max3=1;
	}
	return;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z; 
			check(a[i].x,a[i].y,a[i].z,i);
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].max1<<" "<<a[i].max2<<" "<<a[i].max3<<"\n";
//		}
		for(int i=1;i<=3;i++){
			if(ans[i].cur<2){
				for(int j=1;j<=n;j++){
					if(a[j].max1==i&&a[j].f==true){
						ans[i].num+=a[j].x;
						a[j].f=false;
						ans[i].cur++;
					}else if(a[j].max2==i&&a[j].f==true){
						ans[i].num+=a[j].y;
						a[j].f=false;
						ans[i].cur++;
					}else if(a[j].max3==i&&a[j].f==true){
						ans[i].num+=a[j].z;
						a[j].f=false;
						ans[i].cur++;
					}
				}
			}
		}	
		long long tot=ans[1].num+ans[2].num+ans[3].num;
		cout<<tot<<"\n";
	}
	return 0;
}






