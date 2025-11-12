#include<bits/stdc++.h>
using namespace std;
int t,n,ii[5];
long long x1,x2,x3,x4;
struct node{
int x,y,z;
}a[100100];
bool bmp(node a1,node a2){
	 return a1.x+max(a2.y,a2.z)>a2.x+max(a1.y,a1.z);
}
bool cmp(node a1,node a2){
	return a1.y+max(a2.x,a2.z)>a2.y+max(a1.x,a1.z);
}
bool dmp(node a1,node a2){
	 return a1.z+max(a2.x,a2.y)>a2.z+max(a1.x,a1.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int lkg=1;lkg<=t;lkg++){
		x1=0;
		x2=0;
		x3=0;
		x4=0;
		ii[1]=0;
		ii[2]=0;
		ii[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,bmp);
		for(int i=1;i<=n/2;i++)x1+=a[i].x;
		for(int i=n/2+1;i<=n;i++)x1+=max(a[i].y,a[i].z);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++)x2+=a[i].y;
		for(int i=n/2+1;i<=n;i++)x2+=max(a[i].x,a[i].z);
		sort(a+1,a+1+n,dmp);
		for(int i=1;i<=n/2;i++)x3+=a[i].z;
		for(int i=n/2+1;i<=n;i++)x3+=max(a[i].y,a[i].x);
		for(int i=1;i<=n;i++){
            if(a[i].z>a[i].x&&a[i].z==a[i].y){
				x4+=a[i].z;
				if(ii[2]<=ii[3])ii[2]++;
				else ii[3]++;
			}
			else if(a[i].x>a[i].z&&a[i].x==a[i].y){
				x4+=a[i].x;
				if(ii[2]<=ii[1])ii[2]++;
				else ii[1]++;
			}
			else if(a[i].x>a[i].y&&a[i].x==a[i].z){
				x4+=a[i].x;
				if(ii[1]<=ii[3])ii[1]++;
				else ii[3]++;
			}
			else if(a[i].x>a[i].y&&a[i].x>a[i].z){
				x4+=a[i].x;
				ii[1]++;
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				x4+=a[i].y;
				ii[2]++;
			}
			else if(a[i].z>a[i].x&&a[i].z>a[i].y){
				x4+=a[i].z;
				ii[3]++;
			}
		}
		if(ii[1]>n/2||ii[2]>n/2||ii[3]>n/2)x4=-1;
		cout<<max(x1,max(x2,max(x3,x4)))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
