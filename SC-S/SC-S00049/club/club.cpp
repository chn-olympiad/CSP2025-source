#include<bits/stdc++.h>
using namespace std;
int T,n;
bool flag1,flag2,flag3;
struct node{
	int i1,i2,i3;
}a[100012];
int ans1,ans2,ans3,ans;
bool cmp1(node a,node b){
	return a.i1<b.i1;
}
bool cmp2(node a,node b){
	return a.i2<b.i2;
}
bool cmp3(node a,node b){
	return a.i3<b.i3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		ans1=0,ans2=0,ans3=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].i1,&a[i].i2,&a[i].i3);
			if(a[i].i2||a[i].i3) flag1=1;
			if(a[i].i3||a[i].i1) flag2=1;
			if(a[i].i2||a[i].i1) flag3=1;		
		}
	if(flag1==0){
		sort(a+1,a+1+n,cmp1);
		for(int i=n;i>n/2;i--){
			ans+=a[i].i1;
		}
		cout<<ans<<endl;
		continue;
	}
	if(flag2==0){
		sort(a+1,a+1+n,cmp2);
		for(int i=n;i>n/2;i--){
			ans+=a[i].i2;
		}
		cout<<ans<<endl;
		continue;		
	}
	if(flag3==0){
		sort(a+1,a+1+n,cmp3);
		for(int i=n;i>n/2;i--){
			ans+=a[i].i3;
		}
		cout<<ans<<endl;
		continue;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=n;i>n/2;i--)
		ans1+=a[i].i1;
	for(int i=n/2;i>=0;i--)
		ans1+=max(a[i].i2,a[i].i3);
	sort(a+1,a+1+n,cmp2);
	for(int i=n;i>n/2;i--)
		ans2+=a[i].i2;
	for(int i=n/2;i>=0;i--)
		ans2+=max(a[i].i1,a[i].i3);
	sort(a+1,a+1+n,cmp3);
	for(int i=n;i>n/2;i--)
		ans3+=a[i].i3;
	for(int i=n/2;i>=0;i--)
		ans3+=max(a[i].i2,a[i].i1);
	cout<<max(ans1,max(ans2,ans3))<<endl;
}
	return 0;
}