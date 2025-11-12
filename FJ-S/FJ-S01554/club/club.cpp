#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;i++)
#define pr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int t;
struct mem{
	int a,b,c;
	bool operator<(const mem &t){
		if(a!=t.a)return a<t.a;
		else if(b!=t.b)return b<t.b;
	}
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		rp(i,1,n)cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+1+n);
		pr(i,n,n/2+1)ans+=a[i].a;
		pr(i,n/2,1)ans+=a[i].b;
		cout<<ans<<endl;
	}
}
/*
感觉第一题就已经是较难的黄题了 
*/ 
// 
