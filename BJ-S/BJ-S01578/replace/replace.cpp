#include <bits/stdc++.h>
using namespace std;
#define p 131
int n, q, mxl;
unsigned long long h1[200002], h2[200002], q1[2500002], q2[2500002], base[2500002], bp1[200002], bp2[200002], tr[2500002], manans[200002];
string s1[200002], s2[200002];
int a;
string t1, t2;
priority_queue<pair<int, pair<pair<int, int>, int> >, vector<pair<int, pair<pair<int, int>, int> > >, greater<pair<int, pair<pair<int, int>, int> > > > qu;
int lowbit(int x){
	return x&(-x);
}
void insert(int x){
	while(x<=mxl){
		tr[x]++;
		x+=lowbit(x);
	}
}
int find(int x){
	int rtn=0;
	while(x){
		rtn+=tr[x];
		if(tr[x]){
//			cout<<"rtn += "<<tr[x]<<endl;
		}
		x-=lowbit(x);
	}
	return rtn;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>s1[i]>>s2[i];
		for(int j = 1; j <= s1[i].size(); j++){
			h1[i]=h1[i]*p+s1[i][j-1];
			h2[i]=h2[i]*p+s2[i][j-1];
		}
		int man=s1[i].size();
		mxl=max(mxl, man);
	//	cout<<h1[i]<<" "<<h2[i]<<endl;
	}
	if(1ll*n*q<=200000){
		base[0]=1;
		for(int i = 1; i <= mxl; i++){
			base[i]=base[i-1]*p;
		}
		while(q--){
			int ans=0;
			cin>>t1>>t2;
			for(int i = 1; i <= t1.size(); i++){
				q1[i]=q1[i-1]*p+t1[i-1];
				q2[i]=q2[i-1]*p+t2[i-1];
				base[i]=base[i-1]*p;
			}
		//	cout<<q1[t1.size()]<<" "<<q2[t1.size()]<<endl;
		//	cout<<"t1.size(): "<<t1.size()<<endl;
			for(int i = 1; i <= n; i++){
		//		cout<<"i: "<<i<<endl;
				int lt=t1.size(), ls=s1[i].size();
				for(int j = 0; j <= lt-ls; j++){
		//			cout<<"j: "<<j<<endl;
		//			cout<<"man: "<<q1[j+s1[i].size()]-q1[j]*base[s1[i].size()]<<endl;
					if(q1[j]*base[lt-j]+h2[i]*base[lt-(j+ls)]+q1[lt]-q1[j+ls]*base[lt-(j+ls)]==q2[lt] && q1[j+ls]-q1[j]*base[ls] == h1[i]){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < s1[i].size(); j++){
				if(s1[i][j]=='b'){
					bp1[i]=j;
				}
				if(s2[i][j]=='b'){
					bp2[i]=j;
				}
			}
			qu.push({bp1[i]-bp2[i], {{bp1[i], s1[i].size()-bp2[i]+1}, 0}});
		}
		for(int i = 1; i <= q; i++){
			cin>>t1>>t2;
			int b1=0, b2=0;
			mxl=max(mxl, (int)t1.size());
			for(int i = 0; i < t1.size(); i++){
				if(t1[i]=='b'){
					b1=i;
				}
				if(t2[i]=='b'){
					b2=i;
				}
			}
			qu.push({b1-b2, {{b1, t1.size()-b2+1}, i}});
		}
		int now=1;
		while(!qu.empty()){
			auto [len, p1] = qu.top();
			qu.pop();
			auto [p2, b] = p1;
			auto [l, r] = p2;
	//		cout<<"len: "<<len<<" ("<<l<<", "<<r<<") -- "<<b<<endl;
			if(len!=now){
	//			cout<<"------------------------------------------------------manset---------------------------------------------------------\n";
				memset(tr, 0, sizeof(tr));
				now=len;
			}
			if(b==0){
				insert(r);
			}
			else{
				manans[b]=find(r);
	//			cout<<"ans["<<b<<"] = "<<manans[b]<<endl;
			}
		}
		for(int i = 1; i <= q; i++){
			cout<<manans[i]<<endl;
		}
	}
}