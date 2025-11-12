#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],pos[N];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >>T;
	while(T--){
		int n,cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin >>n;
		for(int i=1;i<=n;i++) cin >>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]) pos[i]=1,ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i]) pos[i]=2,ans+=b[i];
			else if(c[i]>=a[i]&&c[i]>=b[i]) pos[i]=3,ans+=c[i];
			if(pos[i]==1) cnt1++;
			else if(pos[i]==2) cnt2++;
			else if(pos[i]==3) cnt3++;
		}
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				if(pos[i]!=1) continue;
				q.push(a[i]-max(b[i],c[i]));
			}
			while(cnt1>n/2){
				cnt1--;
				ans-=q.top();
				q.pop();
			}
		}
		else if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				if(pos[i]!=2) continue;
				q.push(b[i]-max(a[i],c[i]));
			}
			while(cnt2>n/2){
				cnt2--;
				ans-=q.top();
				q.pop();
			}
		}		
		else if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				if(pos[i]!=3) continue;
				q.push(c[i]-max(a[i],b[i]));
			}
			while(cnt3>n/2){
				cnt3--;
				ans-=q.top();
				q.pop();
			}
		}		
		cout <<ans<<"\n";
		while(!q.empty()) q.pop();
		for(int i=0;i<=100005;i++) pos[i]=a[i]=b[i]=c[i]=0;
	}
	return 0; 
} 
