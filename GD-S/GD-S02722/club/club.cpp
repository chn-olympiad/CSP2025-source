#include<bits/stdc++.h>
#define TIMU (string)"club"
#define ll long long
#define ull unsigned long long
using namespace std;
struct ren{
	int m[4];
	int w = 1;
	void prt(){
		printf("ren %d %d %d\n",m[1],m[2],m[3]);
	}
};
bool cmp(const ren &a,const ren &b){
	/*int aa = a.m[2]-a.m[1];
	int bb = b.m[2]-b.m[1];
	return aa<bb;*/
	return ((a.m[1]>=b.m[1]) );//? 1 : (a.m[2]<b.m[2]));
}
bool cmp1(const ren &a,const ren &b){
	/*int aa = a.m[2]-a.m[1];
	int bb = b.m[2]-b.m[1];
	return aa<bb;*/
	return ((a.m[2]<=b.m[2]) );//? 1 : (a.m[2]<b.m[2]));
}
ren a[100005];
int dp[1005][1005];
int n,t;
int dfs(vector<int> cnt,vector<int> cho,int p){
	//for(int i : cho) cout<<i<<' ';
	//if(p==n) cout<<"SZ";
	//cout<<endl;
	if(p==n){
		if(!(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2)) return 0;
		int cnt = 0;
		//cout<<"--r";
		for(int i = 0;i<cho.size();i++){
			int t = cho[i];
			int r = a[i+1].m[t];
			//cout<<r<<' ';
			cnt += r;
		}
		//cout<<"\n  cnt="<<cnt<<endl;
		return cnt;
	}
	int ans = -114514;
	for(int i = 1;i<=3;i++){
		vector<int> c1 = cnt;
		c1[i]++;
		vector<int> h1 = cho;
		h1.push_back(i);
		ans = max(ans,dfs(c1,h1,p+1));
	}
	return ans;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i].m[1]>>a[i].m[2]>>a[i].m[3];
		}
		bool ok = 0;
		if(!ok){
			int f = 0;
			for(int i = 1;i<=n;i++){
				if(a[i].m[2]!=0||a[i].m[3]!=0) f=1;
			}
			if(f==0){
				sort(a+1,a+n+1,cmp);
				int r = 0;
				for(int i = 1;i<=n/2;i++){
					r += a[i].m[1];
				}
				cout<<r<<endl;
				ok = 1;
			}
		}
		if(!ok && n<=10){
			int r = dfs(vector<int>{0,0,0,0},vector<int>{},0);
			cout<<r<<endl;
			ok = 1;
		}
		if(!ok){
			int cnt = 0;
			for(int i = 1;i<=n;i++){
				int r = -1;
				for(int j = 1;j<=3;j++){
					r = max(r,a[i].m[j]);
				}
				cnt+=r;
			}
			cout<<cnt<<endl;
			ok = 1;
		}
	}
	return 0;
}
/*
1 6
2 1 0
3 2 0
4 3 0
2 2 0
0 1 0
3 1 0
*/








//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
//wish me got prize 2rd or 1st
