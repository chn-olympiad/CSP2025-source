#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
ll ans,sum;
struct node{
	int a,b,c;
}d[100005];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp1(node x,node y){
	return x.b>y.b;
}
bool cmp2(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		sort(d,d+n,cmp);
		for(int i=0;i<n/2;i++){
			sum+=d[i].a;
		}
		for(int i=n/2;i<n;i++){
			sum+=max(d[i].b,d[i].c);
		}
		ans=sum,sum=0;
		sort(d,d+n,cmp1);
		for(int i=0;i<n/2;i++){
			sum+=d[i].b;
		}
		for(int i=n/2;i<n;i++){
			for(int i=n/2;i<n;i++){
				sum+=max(d[i].a,d[i].c);
			}
		}
		ans=max(ans,sum),sum=0;
		sort(d,d+n,cmp2);
		for(int i=0;i<n/2;i++){
			sum+=d[i].c;
		}
		for(int i=n/2;i<n;i++){
			sum+=max(d[i].b,d[i].a);
		}
		ans=max(ans,sum);
		cout<<ans<<endl;
	}
	return 0;
}

