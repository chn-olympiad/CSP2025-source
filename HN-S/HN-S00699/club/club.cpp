#include<bits/stdc++.h>
using namespace std;
int t,n,f;
struct cr{
	int a1,a2,a3,maxn,j;
}a[100005];
bool cmp1(cr x,cr y){
	return x.maxn>y.maxn;
}
bool cmp2(cr x,cr y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int c1=n/2,c2=n/2,c3=n/2,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0){
				f=1;
			}
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){
				a[i].maxn=a[i].a1;
				a[i].j=1;
			}else if(a[i].a1<a[i].a2&&a[i].a2>a[i].a3){
				a[i].maxn=a[i].a2;
				a[i].j=2;
			}else{
				a[i].maxn=a[i].a3;
				a[i].j=3;
			}
		}
		if(f==0){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].j==1&&c1>0){
				ans+=a[i].maxn;
				c1--;
			}else if(a[i].j==2&&c2>0){
				ans+=a[i].maxn;
				c2--;
			}else if(a[i].j==3&&c3>0){
				ans+=a[i].maxn;
				c3--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
