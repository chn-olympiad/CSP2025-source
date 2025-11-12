#include<bits/stdc++.h>
using namespace std;
int n,t,to[5];
struct node{
	long long a,i;
};
bool cmp(node a,node b){
	return a.a>b.a;
}
struct date{
	node a[5];
	int i;
}a[100005];
bool cmp1(date a,date b){
	return a.a[1].a-a.a[2].a>b.a[1].a-b.a[2].a;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[1].a>>a[i].a[2].a>>a[i].a[3].a;
			a[i].i=i;
			a[i].a[1].i=1;
			a[i].a[2].i=2;
			a[i].a[3].i=3;
			sort(a[i].a+1,a[i].a+4,cmp);
		}
		sort(a+1,a+n+1,cmp1);
		memset(to,0,sizeof(to));
		ans=0;
		for(int i=1;i<=n;i++){
			if(to[a[i].a[1].i]*2<n){
				to[a[i].a[1].i]++;
				ans+=a[i].a[1].a;
			}
			else{
				to[a[i].a[2].i]++;
				ans+=a[i].a[2].a;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
