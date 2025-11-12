#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{
	ll id,c,id2;
}a[N],d[5];
ll T,n,ans,cnt[5];
bool cmp(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[1].c>>d[2].c>>d[3].c;
			d[1].id=1,d[2].id=2,d[3].id=3;
			sort(d+1,d+4,cmp);
			a[i].id=d[1].id,a[i].id2=d[2].id;
			a[i].c=d[1].c-d[2].c;
			ans+=d[1].c;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id]<n/2){
				cnt[a[i].id]++;
			}
			else{
				cnt[a[i].id2]++;
				ans-=a[i].c;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) a[i].c=a[i].id=a[i].id2=0;
		for(int i=1;i<=3;i++) d[i].c=d[i].id=cnt[i]=0;
		ans=n=0;
	}
	return 0;
} 
