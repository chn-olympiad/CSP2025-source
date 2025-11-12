#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+10;
int vis[N];
struct node{
	int val,id;
	int g;
}a[N*3];
bool cmp(node a,node b){
	return a.val>b.val;
}
int n,maxn;

int s[4];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		maxn=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		n=0;
		cin>>n;
		for(int i=1;i<=3;i++){
			s[i]=n/2;
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i].val>>a[i+n].val>>a[i+n*2].val;
			a[i].id=a[i+n].id=a[i+n*2].id=i;
		 	a[i].g=1;
			a[i+n].g=2;
			a[i+n*2].g=3;
		}
		
		sort(a+1,a+n*3+1,cmp);
		
		//out();
		for(int i=1;i<=3*n;i++){
			if(!vis[a[i].id]&&s[a[i].g]>=1){
				maxn+=a[i].val;
				vis[a[i].id]=1;
				s[a[i].g]--;
				//printf("id:%d val:%d g:%d maxn:%d vis:%d s:%d\n",a[i].id,a[i].val,a[i].g,maxn,vis[a[i].id],s[a[i].g]);
			}
		}
		cout<<maxn<<'\n';
	}



	return 0;
}

