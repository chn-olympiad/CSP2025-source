#include<bits/stdc++.h>
using namespace std;
int T,n,t[3],x,y,z,a,b,c,maxn,ans;
struct node{
	int f,s;
}d[100010];
bool cmp(node a,node b){
	return a.s<b.s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		t[0]=t[1]=t[2]=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			a=0,b=1,c=2;
			if(x<y){
				swap(x,y);
				swap(a,b);
			}
			if(x<z){
				swap(x,z);
				swap(a,c);
			}
			if(y<z){
				swap(y,z);
				swap(b,c);
			}
			t[a]++;
			d[i].f=a,d[i].s=x-y;
			ans+=x;
		}
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(t[d[i].f]>n/2){
				ans-=d[i].s;
				t[d[i].f]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
