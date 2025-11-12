#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

const int N = 1e5 + 5;
ll T,n,A[N],B[N],C[N],ans;
pll a[N],b[N],c[N];//dis.first -> 第一优势与第二优势之差 dis.second 第二优势部门 
priority_queue < pll,vector <pll> ,greater <pll> > disa,disb,disc;
bool vis[N];

inline bool cmp(pll x,pll y){ return x.first > y.first; }

inline pii calc(ll i,ll flag){
	if(flag == 1){
		if(A[i] == B[i] && B[i] >= C[i])return make_pair(0,2);
		if(A[i] == C[i] && C[i] >= B[i])return make_pair(0,3);
	}
	if(flag == 2){
		if(B[i] == A[i] && A[i] >= C[i])return make_pair(0,1);
		if(B[i] == C[i] && C[i] >= A[i])return make_pair(0,3);
	}
	if(flag == 3){
		if(C[i] == A[i] && A[i] >= B[i])return make_pair(0,1);
		if(C[i] == B[i] && B[i] >= A[i])return make_pair(0,2);
	}
	if(A[i] >= B[i] && B[i] >= C[i])return make_pair(A[i] - B[i],2);
	if(A[i] >= C[i] && C[i] >= B[i])return make_pair(A[i] - C[i],3);
	if(B[i] >= A[i] && A[i] >= C[i])return make_pair(B[i] - A[i],1);
	if(B[i] >= C[i] && C[i] >= A[i])return make_pair(B[i] - C[i],3);
	if(C[i] >= A[i] && A[i] >= B[i])return make_pair(C[i] - A[i],1);
	if(C[i] >= B[i] && B[i] >= A[i])return make_pair(C[i] - B[i],2);
	return {0,0};
}

int main(){
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	//T = 1;
	while(T--){
		while(!disa.empty())disa.pop();
		while(!disb.empty())disb.pop();
		while(!disc.empty())disc.pop();
		ans = 0;
		memset(vis,0,sizeof(vis));
		cin>>n;
		ll x;
		for(ll i = 1;i <= n;i++){
			cin>>x;
			a[i] = make_pair(x,i);
			A[i] = x;
			cin>>x;
			b[i] = make_pair(x,i);
			B[i] = x;
			cin>>x;
			c[i] = make_pair(x,i);
			C[i] = x;
		}
		sort(a + 1,a + n + 1,cmp);
		sort(b + 1,b + n + 1,cmp);
		sort(c + 1,c + n + 1,cmp);
		ll cnta = 0,cntb = 0,cntc = 0,ia = 1,ib = 1,ic = 1;
		while(cnta + cntb + cntc < n){
			//cout<<cnta<<' '<<cntb<<' '<<cntc<<' '<<ans<<'\n';
			while(ia <= n && vis[a[ia].second])ia++;
			while(ib <= n && vis[b[ib].second])ib++;
			while(ic <= n && vis[c[ic].second])ic++;
			ll maxn = a[ia].first,maxi = a[ia].second,flag = 1;
			if(b[ib].first > maxn)maxn = b[ib].first,maxi = b[ib].second,flag = 2;
			if(c[ic].first > maxn)maxn = c[ic].first,maxi = c[ic].second,flag = 3;
			//cout<<flag<<' '<<maxn<<'\n';
			if(flag == 1){
				if(cnta == n / 2){
					pii p = calc(maxi,flag);
					if(p.first <= disa.top().first){
						vis[maxi] = true;
						ans += maxn - p.first;
						if(p.second == 2)cntb++;
						if(p.second == 3)cntc++;
					}
					else{
						vis[maxi] = true;
						ans += maxn - disa.top().first;
						if(disa.top().second == 2)cntb++;
						if(disa.top().second == 3)cntc++;
						if(!disa.empty())disa.pop();
						disa.push(p);
					}
				}
				else{
					vis[maxi] = true;
					cnta++;
					ans += maxn;
					disa.push(calc(maxi,flag));
				}
			}
			else if(flag == 2){
				if(cntb == n / 2){
					pii p = calc(maxi,flag);
					if(p.first <= disb.top().first){
						vis[maxi] = true;
						ans += maxn - p.first;
						if(p.second == 1)cnta++;
						if(p.second == 3)cntc++;
					}
					else{
						vis[maxi] = true;
						ans += maxn - disb.top().first;
						if(disb.top().second == 1)cnta++;
						if(disb.top().second == 3)cntc++;
						if(!disb.empty())disb.pop();
						disb.push(p);
					}
				}
				else{
					vis[maxi] = true;
					cntb++;
					ans += maxn;
					disb.push(calc(maxi,flag));
				}
			}
			else if(flag == 3){
				if(cntc == n / 2){
					pii p = calc(maxi,flag);
					if(p.first <= disc.top().first){
						vis[maxi] = true;
						ans += maxn - p.first;
						if(p.second == 1)cnta++;
						if(p.second == 2)cntb++;
					}
					else{
						
						vis[maxi] = true;
						ans += maxn - disc.top().first;
						if(disc.top().second == 1)cnta++;
						if(disc.top().second == 2)cntb++;
						if(!disc.empty())disc.pop();
						disc.push(p);
					}
				}
				else{
					//cout<<"!"<<maxi<<'\n';
					vis[maxi] = true;
					cntc++;
					ans += maxn;
					disc.push(calc(maxi,flag));
				}
			}
		}
		//cout<<cnta<<' '<<cntb<<' '<<cntc<<' ';
		cout<<ans<<'\n';
	} 
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
