#include<bits/stdc++.h>
using namespace std;
long long n,s[4],ans;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct lis{
	long long d,x;
};
struct node{
	lis x[4];
	long long c;
}a[100005];
bool cmp(lis x,lis y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return x.c>y.c;
}
void so(){
	memset(s,0,sizeof(s));
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		//cin>>a[i].x[1].x>>a[i].x[2].x>>a[i].x[3].x;
		a[i].x[1].x=read(); 
		a[i].x[2].x=read(); 
		a[i].x[3].x=read(); 
		a[i].x[1].d=1;
		a[i].x[2].d=2;
		a[i].x[3].d=3;
		sort(a[i].x+1,a[i].x+4,cmp);
		a[i].c=a[i].x[1].x-a[i].x[2].x;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		//cout<<i<<" : "<<a[i].c<<"\n"<<a[i].x[1].x<<" "<<a[i].x[1].d<<"\n"<<a[i].x[2].x<<" "<<a[i].x[2].d<<"\n"<<a[i].x[3].x<<" "<<a[i].x[3].d<<"\n";
		int to=a[i].x[1].d;
		if(s[to]==n/2){
			ans+=a[i].x[2].x;
			s[a[i].x[2].d]++;
		}else{
			ans+=a[i].x[1].x;
			s[to]++;
		}
	}
	cout<<ans<<"\n"; 
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)so();
	return 0;
} 
