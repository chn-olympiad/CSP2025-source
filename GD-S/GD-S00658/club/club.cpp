#include<bits/stdc++.h>
using namespace std;
struct N{
	int a1;
	int a2;
	int a3;
	int sub1,sub2;
}a[100010];
int cmp(N x,N y){
	if(x.sub1==y.sub1) return x.sub2>y.sub2;
	return x.sub1>y.sub1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,ans=0;
		cin>>n;
		int m1,m2,m3;
		m1=m2=m3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int max1=max(a[i].a1,max(a[i].a2,a[i].a3));
			int max2=a[i].a1+a[i].a2+a[i].a3-min(a[i].a1,min(a[i].a2,a[i].a3))-max(a[i].a1,max(a[i].a2,a[i].a3));
			int max3=min(a[i].a1,min(a[i].a2,a[i].a3));
			a[i].sub1=max1-max2;
			a[i].sub2=max2-max3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int max1=max(a[i].a1,max(a[i].a2,a[i].a3));
			int max2=a[i].a1+a[i].a2+a[i].a3-min(a[i].a1,min(a[i].a2,a[i].a3))-max(a[i].a1,max(a[i].a2,a[i].a3));
			int max3=min(a[i].a1,min(a[i].a2,a[i].a3));
			if(max1==a[i].a1&&m1!=0){ans+=max1;m1--;}
			else if(max1==a[i].a2&&m2!=0){ans+=max1;m2--;}
			else if(max1==a[i].a3&&m3!=0){ans+=max1;m3--;}
			else if(max2==a[i].a1&&m1!=0){ans+=max2;m1--;}
			else if(max2==a[i].a2&&m2!=0){ans+=max2;m2--;}
			else if(max2==a[i].a3&&m3!=0){ans+=max2;m3--;}
			else if(max3==a[i].a1&&m1!=0){ans+=max3;m1--;}
			else if(max3==a[i].a2&&m2!=0){ans+=max3;m2--;}
			else if(max3==a[i].a3&&m3!=0){ans+=max3;m3--;}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
