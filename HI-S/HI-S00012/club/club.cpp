#include<bits/stdc++.h>
using namespace std;
int n,zd,xa,ya,za;
int ans,zans[10]={0};
bool comp(int k,int l){
	return k>l;
}
struct hhh{
	int x,y,z;
}a[100005];
void test(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	zd=n/2;
for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].x<a[j].x){
				xa=a[i].x;
				a[i].x=a[j].x;
				a[j].x=xa;
			}
		
	}
}
	for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[i].x+a[j].y+a[k].z;
				if(ans>zans[1]) zans[1]=ans;
			}
		}
	}
for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[j].x+a[k].y+a[i].z;
				if(ans>zans[2]) zans[2]=ans;
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[k].x+a[i].y+a[j].z;
				if(ans>zans[3]) zans[3]=ans;
			}
		}
	}for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[i].x+a[k].y+a[j].z;
				if(ans>zans[4]) zans[4]=ans;
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[j].x+a[i].y+a[k].z;
				if(ans>zans[5]) zans[5]=ans;
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=i+1;j<=n/2+i;j++){
			for(int k=i+1;k<=n/2+j;k++){
				ans=a[k].x+a[j].y+a[i].z;
				if(ans>zans[6]) zans[6]=ans;
			}
		}
	}
	sort(zans+1,zans+1+6,comp);
	cout<<zans[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		test();
	}
	return 0;
}
