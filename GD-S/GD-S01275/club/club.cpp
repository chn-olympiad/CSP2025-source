#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int mod = 0;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 100010;
int n,m;
ll ans;
struct stu{
	int a,b,c;
	//int sta;
	int pri;
	bool operator<(stu o)const{
		//if(sta==1)return c-a>o.c-o.a;//ѡA
		//else if(sta==2) return c-a>o.c-o.a;//ѡB 
		//else{
			if(pri != o.pri)return pri>o.pri;
			return max(a,b)>max(o.a,o.b);
		//} 
	}
}arr[N];
int cnta,cntb,cntc;
void dfs(int p,ll res){
	if(p>n){
		ans = max(ans,res);
		return;
	}
	if(cnta<n/2){
		cnta++;
		dfs(p+1,res+arr[p].a);
		cnta--;
	}
	if(cntb<n/2){
		cntb++;
		dfs(p+1,res+arr[p].b);
		cntb--;
	}
	if(cntc<n/2){
		cntc++;
		dfs(p+1,res+arr[p].c);
		cntc--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	int a,b,c;
	cin>>T;
	while(T--){
		cin>>n;
		cnta = cntb = cntc = 0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			arr[i] = {a,b,c};
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
