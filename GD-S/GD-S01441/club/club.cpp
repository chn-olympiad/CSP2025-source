#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int cha;
};
int n,t;
node a[100010];
bool cmp1(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.cha>b.cha;
}
int solve1(){
	int ans1=0,ans2=0,ans3=0;
	ans1=a[1].a+max(a[2].b,a[2].c);
	ans2=a[1].b+max(a[2].a,a[2].c);
	ans3=a[1].c+max(a[2].a,a[2].b);
	ans1=max(ans1,max(ans2,ans3));
	cout<<ans1<<endl;
	return 0;
}
int solve3(){
	sort(a+1,a+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a;
	}
	cout<<ans<<endl;
	return 0;
}
int solve4(){
	sort(a+1,a+n+1,cmp2);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans+=a[i].a;
		else ans+=a[i].b;
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)f=0;
			a[i].cha=a[i].a-a[i].b;
		}
		if(n==2)solve1();
		else if(n<=100000&&f)solve3();
		else solve4();
	}
	return 0;
}
