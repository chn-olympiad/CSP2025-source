#include<bits/stdc++.h>
using namespace std;
int a[4];
struct fun{
	int a1,a2,a3,max,max1,all;
};
bool cmp(fun x,fun y){
	return x.a1>y.a1;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		if(n==2){
			int max=0;
			int m[2][3];
			for(int j=0;j<2;j++){
				for(int k=0;k<3;k++){
					cin>>m[j][k];
				}
			}
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(j!=k)
					if(m[0][j]+m[1][k]>max){
						max=m[0][j]+m[1][k];
					}
				}
			}
			cout<<max<<endl;
			break;
		}
		fun m[n];
		int sum=0,sum1=0;
		for(int j=0;j<n;j++){
			cin>>m[j].a1>>m[j].a2>>m[j].a3;
			if(m[j].a2==0){
				sum++;
			}
			if(m[j].a3==0){
				sum++;
			}
			m[j].all=m[j].a1+m[j].a2+m[j].a3;
		}
		if(sum==n*2){
			sort(m,m+n-1,cmp);
			for(int j=0;j<n/2;j++){
				sum1+=m[j].a1;
			}
			cout<<sum1;
			break;
		}
	}
	return 0;
}
