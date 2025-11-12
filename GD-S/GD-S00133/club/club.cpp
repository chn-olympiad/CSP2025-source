#include <iostream>
#include <queue>

using namespace std;

const int N=1e5+5;

int t,n,a[N][3],cnt[3],c[N],ans;

void work(){
	cin>>n,ans=0;
	for (int i=1;i<=n;i++){
		int mx=0;
		for (int j=0;j<3;j++)
			cin>>a[i][j],mx=max(mx,a[i][j]);
		ans+=mx;
		for (int j=0;j<3;j++)
			if (a[i][j]==mx){
				c[i]=j;
				break;
			}
	}
	cnt[0]=cnt[1]=cnt[2]=0;
	for (int i=1;i<=n;i++)
		cnt[c[i]]++;
	int p=0;
	for (int i=1;i<3;i++)
		if (cnt[i]>cnt[p]) p=i;
	if (cnt[p]*2<=n){
		cout<<ans<<"\n";
		return;
	}
	priority_queue<int> q;
	for (int i=1;i<=n;i++)
		if (c[i]==p){
			int val=0;
			for (int j=0;j<3;j++)
				if (j^p) val=max(val,a[i][j]);
			q.push(val-a[i][p]);
		}
	for (int i=1;i<=cnt[p]-n/2;i++)
		ans+=q.top(),q.pop();
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while (t--)
		work();
	return cout<<flush,0;
}

