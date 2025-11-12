#include<bits/stdc++.h>
using namespace std;
struct m{
	int a,b,c;
}a[100005];
//bool cmp(m a,m b){
//	return a.a+a.b+a.c<b.a+b.b+b.c; 
//}
//struct k{
//	int d,ca,cb,cc;
//}d[100005];
int n;
int f(int c,int ca,int cb,int cc){
	if(c==n+1) return 0;
	int ret=0;
	if(ca<n/2) ret=max(ret,f(c+1,ca+1,cb,cc)+a[c].a);
	if(cb<n/2) ret=max(ret,f(c+1,ca,cb+1,cc)+a[c].b);
	if(cc<n/2) ret=max(ret,f(c+1,ca,cb,cc+1)+a[c].c);
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
//		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		cout<<f(1,0,0,0)<<endl;
	}
	return 0;
}

