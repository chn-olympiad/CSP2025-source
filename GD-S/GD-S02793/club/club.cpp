#include<bits/stdc++.h>
using namespace std;
struct node{
	pair<int,int>x[4];
}a[100001];
int n;
bool cmp2(pair<int,int>a,pair<int,int>b){
	if(a.first==b.first)return a.second<b.second;
	else return a.first>b.first;
}
bool cmp(node a,node b){
	if(a.x[1].first-a.x[2].first!=b.x[1].first-b.x[2].first)return a.x[1].first-a.x[2].first>b.x[1].first-b.x[2].first;
	else if(a.x[2].first-a.x[3].first!=b.x[2].first-b.x[3].first)return a.x[2].first-a.x[3].first>b.x[2].first-b.x[3].first;
	else return a.x[1].first>a.x[2].first;
}
void print(int id){
	cout<<a[id].x[1].first<<" "<<a[id].x[1].second<<endl;
	cout<<a[id].x[2].first<<" "<<a[id].x[2].second<<endl;
	cout<<a[id].x[3].first<<" "<<a[id].x[3].second<<endl;
}
void mian(){
	cin>>n;
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[i].x[1]={x,1};
		a[i].x[2]={y,2};
		a[i].x[3]={z,3};
		sort(a[i].x+1,a[i].x+4,cmp2);
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<=n;i++){
		//print(i);
		if(cnt[a[i].x[1].second]==n/2){
			if(cnt[a[i].x[2].second]==n/2){
				cnt[a[i].x[3].second]++;
			    sum+=a[i].x[3].first;			
		    }else{
			    cnt[a[i].x[2].second]++;
			    sum+=a[i].x[2].first;
		    }
		}else{
			cnt[a[i].x[1].second]++;
			sum+=a[i].x[1].first;
		}
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)mian();
	return 0;
} 
