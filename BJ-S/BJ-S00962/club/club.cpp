#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int cnt[5];
pair<int,int> tmp[5];
struct node{
	int x,y,z;
}a[N];
int max1(node x){
	return max({x.x,x.y,x.z});
}
int max2(node x){
	if(x.x==max1(x)) return max(x.y,x.z);
	if(x.y==max1(x)) return max(x.x,x.z);
	return max(x.x,x.y);
}
int max3(node x){
	return min({x.x,x.y,x.z});
}
bool cmp(node x,node y){
	int x1=max1(x),x2=max2(x),x3=max3(x);
	int y1=max1(y),y2=max2(y),y3=max3(y);
	if(x1+y2!=x2+y1){
		return x1+y2>x2+y1;
	}
	if(x1+y3!=x3+y1){
		return x1+y3>x3+y1;
	}
	if(x2+y3!=x3+y2){
		return x2+y3>x3+y2;
	}
	if(x1!=y1) return x1>y1;
	if(x2!=y2) return x2>y2;
	return x3>y3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=node{x,y,z};
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			tmp[1]={a[i].x,1},tmp[2]={a[i].y,2},tmp[3]={a[i].z,3};
			sort(tmp+1,tmp+4);
			for(int j=3;j>=1;j--){
				if(cnt[tmp[j].second]<n/2){
					cnt[tmp[j].second]++,ans+=tmp[j].first;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
