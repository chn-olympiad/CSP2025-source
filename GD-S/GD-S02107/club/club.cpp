#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
int t,n;
struct node{
	int a,b,c,maxn,minn,mid,cha,id;
}; 
bool cmp(const node&x,const node&y){
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		vector<node>a(n+10);
		vector<int>vis(4,0);
		F(i,1,n){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxn=max({a[i].a,a[i].b,a[i].c});
			a[i].minn=min({a[i].a,a[i].b,a[i].c});
			int MAX_ID=0,MIN_ID=0,MID_ID=0;
			if(a[i].a==a[i].maxn)MAX_ID=1;
			else if(a[i].b==a[i].maxn)MAX_ID=2;
			else if(a[i].c==a[i].maxn)MAX_ID=3;
			if(a[i].a==a[i].minn)MIN_ID=1;
			else if(a[i].b==a[i].minn)MIN_ID=2;
			else if(a[i].c==a[i].minn)MIN_ID=3;
			if(MAX_ID+MIN_ID==3)a[i].mid=a[i].c;
			else if(MAX_ID+MIN_ID==4)a[i].mid=a[i].b;
			else if(MAX_ID+MIN_ID==5)a[i].mid=a[i].a;
			a[i].cha=a[i].maxn-a[i].mid;
			a[i].id=i;
		}
		sort(begin(a)+1,begin(a)+n+1,cmp);
		F(i,1,n){
			int MAX_ID=0,MID_ID=0;
			if(a[i].a==a[i].maxn)MAX_ID=1;
			else if(a[i].b==a[i].maxn)MAX_ID=2;
			else if(a[i].c==a[i].maxn)MAX_ID=3;
			if(a[i].a==a[i].mid)MID_ID=1;
			else if(a[i].b==a[i].mid)MID_ID=2;
			else if(a[i].c==a[i].mid)MID_ID=3;
			if(vis[MAX_ID]<n/2){
				vis[MAX_ID]++;
				ans+=a[i].maxn;
			}else{
				vis[MID_ID]++;
				if(MID_ID==1)ans+=a[i].a;
				else if(MID_ID==2)ans+=a[i].b;
				else if(MID_ID==3)ans+=a[i].c;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
/*
可能是按照差异值来排序，贪心的选元素
考虑差异越大，影响越大！
大样例全过，AC！！！ 
*/
