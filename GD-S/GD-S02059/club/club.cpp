#include<bits/stdc++.h>
using namespace std;
struct tt {
	int in[4];
} a[101100];


int an[101100];
bool cmp(int a,int b){
	return a>b;
}
void ai() {
	int n;
	long long ans=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(an,0,sizeof(an));
	vector<int> cnt[4];
	for(int i=1,x,y,z; i<=n; i++) {
		scanf("%d%d%d",&x,&y,&z);
		a[i].in[1]=x;
		a[i].in[2]=y;
		a[i].in[3]=z;
		if(x>=y&&x>=z) {
			cnt[1].push_back(i);
			ans+=a[i].in[1];
		} else if(y>=x&&y>=z) {
			cnt[2].push_back(i);
			ans+=a[i].in[2];
		} else {
			cnt[3].push_back(i);
			ans+=a[i].in[3];
		}
	}
	int k=0,l=0;
	if(cnt[1].size()>n/2) {
		k=1;
		l=cnt[1].size();
	}
	if(cnt[2].size()>n/2) {
		k=2;
		l=cnt[2].size();
	}
	if(cnt[3].size()>n/2) {
		k=3;
		l=cnt[3].size();
	}
	if(k==0) {
		cout<<ans<<endl;
		return ;
	}
	if(k==1) {
		for(int i=0; i<l; i++) {
			int l=cnt[1][i];
			an[i+1]=a[l].in[1]-max(a[l].in[2],a[l].in[3]);
		}
	}
	if(k==2) {
		for(int i=0; i<l; i++) {
			int l=cnt[2][i];
			an[i+1]=a[l].in[2]-max(a[l].in[1],a[l].in[3]);
		}
	}
	if(k==3) {
		for(int i=0; i<l; i++) {
			int l=cnt[3][i];
			an[i+1]=a[l].in[3]-max(a[l].in[1],a[l].in[2]);
		}
	}sort(an+1,an+1+l,cmp);
	for(int i=l;i>n/2;i--){
		ans-=an[i];
	}
	cout<<ans<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		ai();
	}
	return 0;
}
