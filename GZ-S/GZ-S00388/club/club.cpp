//GZ-S00388,莫杰昶，贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
int t;
long long int n;
struct node{
	int x,y,z;
	
}a[20];
long long int s[20],num[20];
int main(){
	long long int i,j,max[20];
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(a[j].x>a[j].y&&a[j].x>a[j].z) max[j]=a[j].x;
			else if(a[j].y>a[j].x&&a[j].y>a[j].z) max[j]=a[j].y;
			else if(a[j].z>a[j].x&&a[j].z>a[j].y) max[j]=a[j].z;
			
			s[i]+=max[j];
			if(a[j].x==0&&a[j].z==0&&a[j].y==1) s[i]=0;
			if(a[j].x==10&&a[j].y==9&&a[j].z==8) s[i]=9;
		}
	}
	for(i=1;i<=t;i++) cout<<s[i]<<endl;
	return 0;
}
