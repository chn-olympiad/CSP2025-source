#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
struct node{
	int my,g,km;
}a[300005];
int cnt;
bool cmp(node x,node y){
	return x.my>y.my;
}
int rs[5];
map<int,int> girl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;_++){
		cnt=0;
		rs[1]=rs[2]=rs[3]=rs[4]=0;
		cin>>n;
		ans=0;
		girl.clear();
		for(int i=1;i<=n;i++){
			cin>>a[++cnt].my;
			a[cnt].g=i;
			a[cnt].km=1;
			cin>>a[++cnt].my;
			a[cnt].g=i;
			a[cnt].km=2;
			cin>>a[++cnt].my;
			a[cnt].g=i;
			a[cnt].km=3;
		}
		sort(a+1,a+1+3*n,cmp);
		for(int i=1;i<=n*3;i++){
			if(girl[a[i].g]==1)continue;
			if(rs[a[i].km]>=n/2)continue;
			ans+=a[i].my;
			girl[a[i].g]=1;
			rs[a[i].km]++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
