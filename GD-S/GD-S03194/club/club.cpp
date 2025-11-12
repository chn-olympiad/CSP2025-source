#include<bits/stdc++.h>
using namespace std;
int n,cnt[4],ans,T;
struct node{
	int a,b,c;
}p[100010];
int maxx(node x){
	return max({x.a,x.b,x.c});
}
int minn(node x){
	return min({x.a,x.b,x.c});
}
int midd(node x){
	return (x.a+x.b+x.c)-maxx(x)-minn(x);
}
bool cmp(node x,node y){
	return maxx(x)-midd(x)>maxx(y)-midd(y);
}
int mx(node x){
	if(x.a>=x.b&&x.a>=x.c)return 1;
	else if(x.b>x.a&&x.b>=x.c)return 2;
	else return 3;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[mx(p[i])]<(n/2)){
				cnt[mx(p[i])]++;
				ans+=maxx(p[i]);
			}
			else{
				ans+=midd(p[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
