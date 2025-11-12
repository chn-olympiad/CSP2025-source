#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int T,n,m;
struct node{
	int x,y,z,id;
	int mx;
}a[N];
int cnta,cntb,cntc,ans;
priority_queue<int> q1,q2,q3;
void clear(){
	cnta=cntb=cntc=n=m=ans=0;
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}
void xpigeon(){
	cin>>n;
	m=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id=i;
		a[i].mx=max({a[i].x,a[i].y,a[i].z});
	}
	for(int i=1;i<=n;i++){
		if(a[i].mx==a[i].x){
			cnta++;
			//替换后的代价
			q1.push(max(a[i].y,a[i].z)-a[i].mx);
		}else if(a[i].mx==a[i].y){
			cntb++;
			q2.push(max(a[i].x,a[i].z)-a[i].mx);
		}else if(a[i].mx==a[i].z){
			cntc++;
			q3.push(max(a[i].y,a[i].x)-a[i].mx);
		}
		ans+=a[i].mx;
	}
	//cout<<"!!!"<<ans<<'\n';
	if(cnta>m){
		//cout<<111<<'\n';
		int k=cnta-m;
		while(k--){
			ans+=q1.top();
			q1.pop();
		}
	}
	if(cntb>m){
		//cout<<222<<'\n';
		int k=cntb-m;
		while(k--){
			ans+=q2.top();
			q2.pop();
		}
	}
	if(cntc>m){
		int k=cntc-m;
		while(k--){
			//cout<<q3.top()<<'\n';
			ans+=q3.top();
			q3.pop();
		}
	}
	cout<<ans<<'\n';
	clear();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) xpigeon();
	return 0;
}
//不次卡次次不卡次不不卡次次不卡次