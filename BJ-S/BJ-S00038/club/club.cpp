#include<bits/stdc++.h>
using namespace std;
struct node{
int x;
int y;
int z;
int fs;
}a[100001];
bool cmp(node e,node f){
	e.fs=max(e.x,max(e.y,e.z));
	f.fs=max(f.x,max(f.y,f.z));
	return e.fs>f.fs;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int sd=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
		}
		int sum=0,p1=0,p2=0,p3=0;
		sort(a+1,a+1+n,cmp);
		for(int j=1;j<=n;j++){
			a[j].fs=max(a[j].x,max(a[j].y,a[j].z));
			if(p1<=sd&&a[j].fs==a[j].x){
				sum+=a[j].x;
				p1++;
			}else if(p2<=sd&&a[j].fs==a[j].y){
				sum+=a[j].y;
				p2++;
			}else if(p3<=sd&&a[j].fs==a[j].z){
				sum+=a[j].z;
				p3++;
			}	
		}
		cout<<sum<<endl;
		for(int j=1;j<=n;j++){
			a[j].x=0;
			a[j].y=0;
			a[j].z=0;
		}n=0;
	}
	return 0;
}