#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a1,a2,a3;
}a[100005];
int n,q1,q2,q3,ans,t;
bool cmp(stu x,stu y){
	if(x.a1!=y.a1)return x.a1>y.a1;
	if(x.a2!=y.a2)return x.a2>y.a2;
	return x.a3>y.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,q1=q2=q3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=a[i].a1;
		cout<<ans<<endl;
	}
}
