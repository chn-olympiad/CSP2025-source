#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n[10];
int q[100001];
struct student{
	int a1[100001],a2[100001],a3[100001];
	int b1[100001],b2[100001],b3[100001];
	int c1[100001],c2[100001],c3[100001];
	int x,y,z;
	int all;
}a[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i].a1[j]>>a[i].a2[j]>>a[i].a3[j];
			if(a[i].a1[j]>=a[i].a2[j]){
				a[i].c1[j]=1;
				a[i].c3[j]=2;
				a[i].b1[j]=a[i].a1[j];
				a[i].b3[j]=a[i].a2[j];
			}
			else{
				a[i].c1[j]=2;
				a[i].c3[j]=1;
				a[i].b1[j]=a[i].a2[j];
				a[i].b3[j]=a[i].a1[j];
			}
			if(a[i].a3[j]>=a[i].b1[j]){
				a[i].b2[j]=a[i].b1[j];
				a[i].b1[j]=a[i].a3[j];
				a[i].c2[j]=a[i].c1[j];
				a[i].c1[j]=3;
			}
			else if(a[i].a3[j]<=a[i].b3[j]){
				a[i].b2[j]=a[i].b3[j];
				a[i].b3[j]=a[i].a3[j];
				a[i].c2[j]=a[i].c3[j];
				a[i].c3[j]=3;
			}
			else{
				a[i].b2[j]=a[i].a3[j];
				a[i].c2[j]=3;
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			if(a[i].c1[j]==1){
				a[i].x++;
			}
			else if(a[i].c1[j]==2){
				a[i].y++;
			}
			else if(a[i].c1[j]==3){
				a[i].z++;
			}
			a[i].all+=a[i].b1[j];
		}
		if(a[i].x<=n[i]/2&&a[i].y<=n[i]/2&&a[i].z<=n[i]/2){
			cout<<a[i].all<<endl;
		}
		else{
			if(a[i].x>n[i]/2){
				int m=a[i].x-n[i]/2;
				int sum=1;
				for(int j=1;j<=n[i];j++){
					if(a[i].c1[j]==1){
						q[sum]=a[i].b1[j]-a[i].b2[j];
						sum++;
					}
				}
				sort(q+1,q+sum);
				for(int j=1;j<=m;j++){
					a[i].all-=q[j];
				}
				cout<<a[i].all<<endl;
			}
			else if(a[i].y>n[i]/2){
				int m=a[i].y-n[i]/2;
				int sum=1;
				for(int j=1;j<=n[i];j++){
					if(a[i].c1[j]==2){
						q[sum]=a[i].b1[j]-a[i].b2[j];
						sum++;
					}
				}
				sort(q+1,q+sum);
				for(int j=1;j<=m;j++){
					a[i].all-=q[j];
				}
				cout<<a[i].all<<endl;
			}
			else if(a[i].z>n[i]/2){
				int m=a[i].z-n[i]/2;
				int sum=1;
				for(int j=1;j<=n[i];j++){
					if(a[i].c1[j]==3){
						q[sum]=a[i].b1[j]-a[i].b2[j];
						sum++;
					}
				}
				sort(q+1,q+sum);
				for(int j=1;j<=m;j++){
					a[i].all-=q[j];
				}
				cout<<a[i].all<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
