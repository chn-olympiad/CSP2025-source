#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
vector<int> v[5];
struct want{
	int num,name;
};
struct node{
	want w[5];
	int c1,c2;
}a[100005];
bool cmp1(node t1,node t2){
	if(t1.w[1].num!=t2.w[1].num) return t1.w[1].num>t2.w[1].num;
	else if(t1.w[2].num!=t2.w[2].num) return t1.w[2].num>t2.w[2].num;
	else if(t1.w[3].num!=t2.w[3].num) return t1.w[3].num>t2.w[3].num;
	return 1;
}
bool cmp2(want t1,want t2){
	return t1.num>t2.num;
}
bool cmp3(node t1,node t2){
	if(t1.c1!=t2.c1) return t1.c1>t2.c1;
	else if(t1.c2!=t2.c2) return t1.c2>t2.c2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		for(int i=1;i<=4;i++) v[i].clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].w[j].num;
				a[i].w[j].name=j;
			}
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			sort(a[i].w+1,a[i].w+4,cmp2);
			a[i].c1=a[i].w[1].num-a[i].w[2].num;
			a[i].c2=a[i].w[2].num-a[i].w[3].num;
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(v[a[i].w[1].name].size()+1<=n/2) v[a[i].w[1].name].push_back(a[i].w[1].num);
			else if(v[a[i].w[2].name+1].size()<=n/2) v[a[i].w[2].name].push_back(a[i].w[2].num);
			else if(v[a[i].w[3].name+1].size()<=n/2) v[a[i].w[3].name].push_back(a[i].w[3].num); 
		}
		for(int i=1;i<=3;i++){
			for(int j=0;j<v[i].size();j++){
				ans+=v[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

