#include<bits/stdc++.h>
using namespace std;

struct st{
	int x1,x2,x3;
	int b1,b2,b3;
	int c1,c2,c3;
}a[100005];

int t,n;
long long ans;

bool cmp(st X,st Y){
	return X.x1>Y.x1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			/*
			b[i].b1=a[i].x1;b[i].b2=a[i].x2;b[i].b3=a[i].x3;
			c[i].c1=a[i].x1;c[i].c2=c[i].x2;c[i].c3=a[i].x3;
			*/
			if(a[i].x2!=0){
				f1=1;
			}
			if(a[i].x3!=0){
				f2=1;
			}
		}
		if(n==2){
			cout<<max(a[1].x1,a[2].x1)+max(a[1].x2,a[2].x2)+max(a[1].x3,a[2].x3)<<"\n";
			continue;
		}
		if(f1==0&&f2==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x1;
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
} 
