#include<bits/stdc++.h>
#define online
#define val first
#define idx second
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
vector<pair<int,int> >wic;
pair<int,int> a[100005][4];
pair<int,int> bm[4];
inline bool cmp(pair<int,int> a,pair<int,int> b){
	return a.val>b.val;
}
inline void solve(){
	int n;cin>>n;
	wic.clear();
	bm[1].val=0,bm[1].idx=0;
	bm[2].val=0,bm[2].idx=0;
	bm[3].val=0,bm[3].idx=0;
	bm[4].val=0,bm[4].idx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
		a[i][1].idx=1,a[i][2].idx=2,a[i][3].idx=3;//默认a[i][1]为他的部门 
		sort(a[i]+1,a[i]+4,cmp);
		bm[a[i][1].idx].val+=a[i][1].val;
		bm[a[i][1].idx].idx++;
	}
	if(bm[1].idx>n/2&&bm[2].idx>n/2){
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==1||a[i][1].idx==2){
				if(a[i][2].idx==3){
					wic.push_back({a[i][1].val-a[i][2].val,i});
				}
				if(a[i][3].idx==3){
					wic.push_back({a[i][1].val-a[i][3].val,i});
				}
			}
		}
		sort(wic.begin(),wic.end());
		for(int i=1;i<=(n/2-bm[1].idx)+(n/2-bm[2].idx);i++){
			bm[3].val+=a[wic[i].idx][1].val-wic[i].val;
			bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}
	else if(bm[3].idx>n/2&&bm[2].idx>n/2){
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==3||a[i][1].idx==2){
				if(a[i][2].idx==1){
					wic.push_back({a[i][1].val-a[i][2].val,i});
				}
				if(a[i][3].idx==1){
					wic.push_back({a[i][1].val-a[i][3].val,i});
				}
			}
		}
		sort(wic.begin(),wic.end());
		for(int i=1;i<=(n/2-bm[3].idx)+(n/2-bm[2].idx);i++){
			bm[1].val+=a[wic[i].idx][1].val-wic[i].val;
			bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}
	else if(bm[1].idx>n/2&&bm[3].idx>n/2){
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==1||a[i][1].idx==3){
				if(a[i][2].idx==2){
					wic.push_back({a[i][1].val-a[i][2].val,i});
				}
				if(a[i][3].idx==2){
					wic.push_back({a[i][1].val-a[i][3].val,i});
				}
			}
		}
		sort(wic.begin(),wic.end());
		for(int i=1;i<=(n/2-bm[1].idx)+(n/2-bm[3].idx);i++){
			bm[2].val+=a[wic[i].idx][1].val-wic[i].val;
			bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}
	else if(bm[1].idx>n/2){//只有这一个 
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==1){
				wic.push_back({a[i][1].val-a[i][2].val,i});
			}
		}
		sort(wic.begin(),wic.end());
		ll gs=bm[1].idx-n/2;
		for(int i=0;i<gs;i++){
			bm[a[wic[i].idx][2].idx].idx++;bm[a[wic[i].idx][2].idx].val+=a[wic[i].idx][2].val;
			bm[a[wic[i].idx][1].idx].idx--;bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}
	else if(bm[2].idx>n/2){//只有这一个
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==2){
				wic.push_back({a[i][1].val-a[i][2].val,i});
			}
		}
		sort(wic.begin(),wic.end());
		ll gs=bm[2].idx-n/2;
		for(int i=0;i<gs;i++){
			bm[a[wic[i].idx][2].idx].idx++;bm[a[wic[i].idx][2].idx].val+=a[wic[i].idx][2].val;
			bm[a[wic[i].idx][1].idx].idx--;bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}
	else if(bm[3].idx>n/2){//只有这一个 
		for(int i=1;i<=n;i++){
			if(a[i][1].idx==3){
				wic.push_back({a[i][1].val-a[i][2].val,i});
			}
		}
		sort(wic.begin(),wic.end());
		ll gs=bm[3].idx-n/2;
		for(int i=0;i<gs;i++){
			bm[a[wic[i].idx][2].idx].idx++;bm[a[wic[i].idx][2].idx].val+=a[wic[i].idx][2].val;
			bm[a[wic[i].idx][1].idx].idx--;bm[a[wic[i].idx][1].idx].val-=a[wic[i].idx][1].val;
		}
	}	
	cout<<bm[1].val+bm[2].val+bm[3].val<<endl; 
}
int main(){
#ifdef online
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	
	return 0;
}
/*
 3
 4
 4 2 1
 3 2 4
 5 3 4
3 5 1
 4
0 1 0
  0 1 0
  0 2 0
  0 2 0
  2
 10 9 8
  4 0 0
*/
