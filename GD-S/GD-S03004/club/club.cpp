#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
} a[100005];
int max2,max3;
bool cmp(node xx,node yy){
	return xx.x<yy.x;
}
int ans=0,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y>max2) max2=a[i].y;
			if(a[i].z>max3) max3=a[i].z;
		}
		if(n==2){
		int maxn=0,maxs;
		char c;
		int c3;
		for(int i=1;i<=n;i++){
			if(a[i].x>maxn){
			maxn=a[i].x;
			c='x';
			c3=i;
		}
			if(a[i].y>maxn) {
			maxn=a[i].y;
			c='y';
			c3=i;
		}
			if(a[i].z>maxn) {
			c='z';
			maxn=a[i].z;
			c3=i;
		}
		}
		if(c3==1){
		if(c=='x') maxs=max(a[2].y,a[2].z);
		if(c=='y') maxs=max(a[2].x,a[2].z);
		if(c=='z') maxs=max(a[2].y,a[2].x);
	}else if(c3==2){
		if(c=='x') maxs=max(a[1].y,a[1].z);
		if(c=='y') maxs=max(a[1].x,a[1].z);
		if(c=='z') maxs=max(a[1].y,a[1].x);
	}
			cout<<maxn+maxs;  
		}
		else if(max2==max3==0){
			sort(a+1,a+n+1,cmp);
			long long sum=0;
			for(int i=n/2;i<=n;i++){
				sum+=a[i].x;
			}
			cout<<sum;
		}
	}
	return 0;
} 
