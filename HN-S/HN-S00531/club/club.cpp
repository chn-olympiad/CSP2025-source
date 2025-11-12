//尽然我不会写 那就写shit山代码 =(    <-这个表情代表了我现在的心情 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
struct ren{
	int one,two,three;
}a[N];
int n;
int dp[N];
int maxs,maxren;
int vis[4];

void init(){
	maxs = 0;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
}

bool cmp(ren x,ren y){
	return (x.one>y.one || (x.one == y.one && x.two > y.two) || (x.one == y.one && x.two == y.two && x.three > y.three));
}

void dfs(int d,int s){
	if(d > n){
		maxs = max(maxs,s);
	}
	if(vis[1] < maxren){
		vis[1]++;
		dfs(d+1,s+a[d].one);
		vis[1]--;//回溯 
	}
	if(vis[2] < maxren){
		vis[2]++;
		dfs(d+1,s+a[d].two);
		vis[2]--;
	}
	if(vis[3] < maxren){
		vis[3]++;
		dfs(d+1,s+a[d].three);
		vis[3]--;
	}
}

int pozvr(){
	init();
	
	cin>>n;
	for(int i = 1;i <= n;i++) scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);
	maxren = n/2;
	
	//A
	int pa = 1,pa2 = 1,pa3 = 1,pb = 1;
	for(int i = 1;i <= n;i++) {
		if(a[i].three == a[i].two && a[i].three == 0 && pa) pa = 1;
		else if(a[i].one == a[i].two && a[i].one == 0 && pa2) pa = 0;
		else if(a[i].three == a[i].one && a[i].three == 0 && pa3) pa = 0,pa2 = 0;
		else if(a[i].three == 0 && pb) pa = pa2 = pa3 = 0;
		else{
			pa = pa2 = pa3 = 0;
			break;
		}
	}
	if(pa == 1){
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= maxren;i++){
			maxs+=a[i].one;
		}
		cout<<maxs<<endl;
		return 0;
	}else if(pa2 == 1){
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= maxren;i++){
			maxs+=a[i].three;
		}
		cout<<maxs<<endl;
		return 0;
	}else if(pa3 == 1){
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= maxren;i++){
			maxs+=a[i].two;
		}
		cout<<maxs<<endl;
		return 0;
	}else if(pb == 1 && n>30){//放手一搏 
		sort(a+1,a+n+1,cmp);
		int p = 0;
		for(int i = 1;i <= n;i++){
			if(vis[1] >= maxren && vis[2] >= maxren && p){
				p--;
				maxs += max(a[i].one,a[i].two);
			}
			if(vis[1] < maxren && a[i].one > a[i].two){
				vis[1]++;
				maxs += a[i].one;
			}else if(vis[2] < maxren && a[i].one < a[i].two){
				vis[2]++;
				maxs += a[i].two;
			}else if(vis[1] >= maxren && vis[2] < maxren){
				for(int j = i;vis[2] < maxren;j++,vis[2]++){
					maxs += a[j].two;
				}
				cout<<maxs<<endl;
				return 0;
			}else if(vis[2] >= maxren && vis[1] < maxren){
				for(int j = i;vis[1] < maxren;j++,vis[1]++){
					maxs += a[j].one;
				}
				cout<<maxs<<endl;
				return 0;
			}else if(a[i].one == a[i].two && vis[1] < maxren && vis[2] < maxren){
				vis[1]++,vis[2]++,p++;
				maxs += a[i].one;
			}else{
				cout<<maxs<<endl;
				return 0;
			}
		}
	}else{
		//正常暴力 (能拿n<30一下的测试点的分) 
		dfs(1,0);
		cout<<maxs<<endl;
	}
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) pozvr();
	return 0;
}

