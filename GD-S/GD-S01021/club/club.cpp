#include<bits/stdc++.h>
using namespace std;
long long k,n;
long long member[5];//成员数
long long sum[5];//总的满意度
struct node{
	long long b[5];
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			long long x=a[i].b[1],y=a[i].b[2],z=a[i].b[3];
			long long x1=member[1],y1=member[2],z1=member[3];
			long long mx1=0,mx2=0,mx3=0;
			if(x>y){
				if(x>z){
					mx1=1;
					if(z>y){
						mx2=3;
						mx3=2;
						cout<<111111111<<endl;
					}else{//z<y
						mx2=2;
						mx3=3;
						cout<<222222222<<endl;
					}
				}else{//x<z 
					mx1=3;
					mx2=1;
					mx3=2;
					cout<<333333333<<endl;
				}
			}else{//x<y
				if(y>z){
					mx1=2;
					if(x>z){
						mx2=1;
						mx3=3;
						cout<<4444444444<<endl;
					}else{//x<z
						mx2=3;
						mx3=1;
						cout<<5555555555<<endl;
					}
				}else{//y<z
					mx1=3;
					mx2=2;
					mx3=1;
					cout<<666666666<<endl;
				}
			}
			if(member[mx1]<=n/2){
				sum[mx1]+=a[i].b[mx1];
				member[mx1]++;
			}else if(member[mx2]<=n/2){
				sum[mx2]+=a[i].b[mx2];
				member[mx2]++;
			}else if(member[mx3]<=n/2){
				sum[mx3]+=a[i].b[mx3];
				member[mx3]++;
			}
		}
		cout<<sum[1]+sum[2]+sum[3]<<endl;
		for(int i=1;i<=3;i++){
			member[i]=0;
			sum[i]=0;
		}
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
