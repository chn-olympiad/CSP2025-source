#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int t,n;
void solve();
void init();
int minn(int a,int b){
	return a>b?b:a;
}
struct node{
	int pi;
	int a1,a2,a3;
	int plus;
	
	void pre(){
		int min=minn(a1,minn(a2,a3));
		plus=min;
		a1=a1-min;a2=a2-min;a3=a3-min;
	}
}a[M];
struct que{
	int head;
	int r[M],a[M];
}q[4];
bool op1 (node a,node b){
	return a.a1>b.a1;
};
bool op2 (node a,node b){
	return a.a2>b.a2;
};
bool op3 (node a,node b){
	return a.a3>b.a3;
};
bool opn (node a,node b){
	return a.pi>b.pi;
};
void init(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].pi=i;
		a[i].pre();
	}
	sort(a+1,a+n+1,op1);
	for(int i=1;i<=n;i++){
	    q[1].r[i]=a[i].a1;q[1].a[i]=a[i].plus;
	}
	sort(a+1,a+n+1,op2);
	for(int i=1;i<=n;i++){
		q[2].r[i]=a[i].a2;q[2].a[i]=a[i].plus;
	}
	sort(a+1,a+n+1,op3);
	for(int i=1;i<=n;i++){
		q[2].r[i]=a[i].a3;q[3].a[i]=a[i].plus;
	}
	sort(a+1,a+n+1,opn);
}
void solve(){
	int b1,b2;
	int ans=0;
	memset(a,0,sizeof(a));
	init();
	for(int i=1;i<=n;i++) ans+=a[i].plus;
	sort(a+1,a+n+1,op1);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a1;
	} 
	cout<<ans<<endl;
}











int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	
	fclose(stdin);fclose(stdout);
	return 0;
}
