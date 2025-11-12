#include<bits/stdc++.h>
using namespace std;

const int _=1e5+5;

int n;
long long ans;
int a[_][5],b[_],c[_],box[5];

void solve(){
	cin>>n;
	memset(box,0,sizeof box);
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==maxn)b[i]=1;
		if(a[i][2]==maxn)b[i]=2;
		if(a[i][3]==maxn)b[i]=3;
		++box[b[i]];
		ans+=maxn;
	}
	int p=0;
	if(box[1]>n/2){
		for(int i=1;i<=n;i++)if(b[i]==1)c[++p]=a[i][1]-max(a[i][2],a[i][3]);
		sort(c+1,c+p+1);
		int num=box[1]-n/2;
		for(int i=1;i<=num;i++)ans-=c[i];
	}
	if(box[2]>n/2){
		for(int i=1;i<=n;i++)if(b[i]==2)c[++p]=a[i][2]-max(a[i][1],a[i][3]);
		sort(c+1,c+p+1);
		int num=box[2]-n/2;
		for(int i=1;i<=num;i++)ans-=c[i];
	}
	if(box[3]>n/2){
		for(int i=1;i<=n;i++)if(b[i]==3)c[++p]=a[i][3]-max(a[i][1],a[i][2]);
		sort(c+1,c+p+1);
		int num=box[3]-n/2;
		for(int i=1;i<=num;i++)ans-=c[i];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
