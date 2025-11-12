#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int n,t,ans=0;
int num[4];
struct node{
	int a,b,c;
	int to;
	int val;
	int maxx;
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
	void init(){
		a=b=c=to=val=0;
	}
	void calc(){
		if(a>=b&&a>=c){
			to=1;
			maxx=a;
			val=min(a-b,a-c);
		}
		else if(b>=a&&b>=c){
			to=2;
			maxx=b;
			val=min(b-a,b-c);
		}
		else if(c>=a&&c>=b){
			to=3;
			maxx=c;
			val=min(c-a,c-b);
		}
	}
}s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=1e5;i++) s[i].init();
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].calc();
		}
		sort(s+1,s+1+n);
		for(int i=1;i<=n;i++){
			if(num[s[i].to]<n/2){
				ans+=s[i].maxx;
				num[s[i].to]++;
			}else{
				ans+=s[i].maxx-s[i].val;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
}
