#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,ans;
struct node{
	int la,lb,lc;
}a[100010];
int ca[100010],cb[100010],cc[100010];
int shishi[100010];
int cou[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=100010;i++){
			a[i].la=0,a[i].lb=0,a[i].lc=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].la>>a[i].lb>>a[i].lc;
		}
		for(int i=1;i<=n;i++){
			int t=max(max(a[i].la,a[i].lb),a[i].lc);
			ans+=t;
			if(t==a[i].la) ca[++cou[0]]=i;
			if(t==a[i].lb) cb[++cou[1]]=i;
			if(t==a[i].lc) cc[++cou[2]]=i;
		}
		for(int i=1;i<=cou[0];i++) ans+=ca[i];
		for(int i=1;i<=cou[1];i++) ans+=cb[i];
		for(int i=1;i<=cou[2];i++) ans+=cc[i];
		cout<<ans;
	}
	return 0;
} 
