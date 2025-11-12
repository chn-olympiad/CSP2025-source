#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
}a[N];
int t;
int n;
int c1[N],c2[N],c3[N],cnt1,cnt2,cnt3;
int cop[N],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		memset(cop,0,sizeof(cop));
		cnt=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++) {
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) c1[++cnt1]=i;
			if(a[i].y>a[i].x&&a[i].y>=a[i].z)  c2[++cnt2]=i;
			if(a[i].z>a[i].y&&a[i].z>a[i].x)   c3[++cnt3]=i;
		}
//		for(int i=1;i<=cnt1;i++) cout<<c1[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=cnt2;i++) cout<<c2[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=cnt3;i++) cout<<c3[i]<<" ";
//		cout<<endl;
		int s=n/2,ans=0;
		if(cnt1<=s&&cnt2<=s&&cnt3<=s) {
			for(int i=1;i<=cnt1;i++) ans+=a[c1[i]].x;
			for(int i=1;i<=cnt2;i++) ans+=a[c2[i]].y;
			for(int i=1;i<=cnt3;i++) ans+=a[c3[i]].z;
			cout<<ans<<endl;
			continue;
		}
		if(cnt1>s){
			for(int i=1;i<=cnt1;i++)
				cop[++cnt]=min(a[c1[i]].x-a[c1[i]].y,a[c1[i]].x-a[c1[i]].y);
		}
		else if(cnt2>s){
			for(int i=1;i<=cnt2;i++)
				cop[++cnt]=min(a[c2[i]].y-a[c2[i]].x,a[c2[i]].y-a[c2[i]].z);			
		}
		else{
			for(int i=1;i<=cnt3;i++)
				cop[++cnt]=min(a[c3[i]].z-a[c3[i]].x,a[c3[i]].z-a[c3[i]].y);				
		}
		sort(cop+1,cop+cnt+1);
		//for(int i=1;i<=cnt;i++) cout<<cop[i]<<" ";
		//cout<<endl;
		int del=max(cnt1,max(cnt2,cnt3));
		for(int i=1;i<=cnt1;i++) ans+=a[c1[i]].x;
		for(int i=1;i<=cnt2;i++) ans+=a[c2[i]].y;
		for(int i=1;i<=cnt3;i++) ans+=a[c3[i]].z;
		for(int i=1;i<=del-s;i++) ans-=cop[i];
		cout<<ans<<endl;
	}
	return 0;
} 








