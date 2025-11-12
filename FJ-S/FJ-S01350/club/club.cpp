#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5];
long long ans;
struct node{
	int on,tw,th;
	int tt(){
		if(max({on,tw,th})==on) return max(tw,th);
		else if(max({on,tw,th})==tw) return max(th,on);
		else return max(on,tw);
	}
}b[100005]; 
bool cmp(node x,node y){
	return max({x.on,x.th,x.tw})-x.tt()<max({y.on,y.th,y.tw})-y.tt();
}
void out(int k,vector<int> cnt){
	int nn=0;
	for(auto i:cnt){
		b[++nn].on=a[i][1];
		b[nn].tw=a[i][2];
		b[nn].th=a[i][3];
	}
	for(int i=1;i<=n;i++){
		ans+=max({a[i][1],a[i][2],a[i][3]});
	}
	sort(b+1,b+1+nn,cmp);
	int len=cnt.size();
	for(int i=1;i<=len-n/2;i++){
		ans-=max({b[i].on,b[i].th,b[i].tw})-b[i].tt();
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		vector<int> cnt[5];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			bool x=(a[i][1]>a[i][2]),y=(a[i][1]>a[i][3]),z=(a[i][2]>a[i][3]);
			bool xd=(a[i][1]==a[i][2]),yd=(a[i][1]==a[i][3]),zd=(a[i][2]==a[i][3]);
			if(x&&y){
				cnt[1].push_back(i);
			}
			else if(z&&(!x)&&(!xd)){
				cnt[2].push_back(i);
			}
			else if((!y)&&(!z)&&(!yd)&&(!zd)){
				cnt[3].push_back(i);
			}
			else{
				cnt[4].push_back(i);
			}
		}
		if(cnt[1].size()<=n/2 && cnt[2].size()<=n/2 && cnt[3].size()<=n/2){
			for(int i=1;i<=n;i++){
				ans+=max({a[i][1],a[i][2],a[i][3]});
			}
			cout<<ans<<"\n";
		}
		else{
			if(cnt[1].size()>n/2) out(1,cnt[1]);
			else if(cnt[2].size()>n/2) out(2,cnt[2]);
			else out(3,cnt[3]);
		}
	}
	return 0;
}

