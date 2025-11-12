#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int T,n,ans,cnt[N];
struct node{
	int a1,a2,a3;
}a[N],b[N];

bool cmp(node a,node b){
	return a.a1>b.a1;
}

int main(){
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool flag=false;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0) flag=1;
		}
		if(!flag){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].a1;
			cout<<ans<<endl; 
		}
		else{
			for(int i=1;i<=n;i++) ans+=max({a[i].a1,a[i].a2,a[i].a3});
			cout<<ans<<endl;
		}
	} 
	return 0;
}
/*
我他妈最糖的一次，我就是个煞笔
*/ 
