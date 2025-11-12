//GZ-S00140 贵州省织金育才学校 宋载航 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e5+9;
ll T=1;
ll n,ans;
struct node{
	ll a,b,c,sum,mx,mi;
}stu[N];
inline void solve(){
	cin>>n;
	ans=0;
	vector<ll> ls;
	for(int i=1;i<=n;i++){
		ls.clear();
		cin>>stu[i].a>>stu[i].b>>stu[i].c;
		ls.emplace_back(stu[i].a),ls.emplace_back(stu[i].b),ls.emplace_back(stu[i].c);
		sort(ls.begin(),ls.end());
		stu[i].sum=stu[i].a+stu[i].b+stu[i].c;
		stu[i].mx=ls[2];
		stu[i].mi=ls[1];
	}
	sort(stu+1,stu+n+1,[](node p,node q)->bool{
		ll res1=p.mx-p.mi;
		ll res2=q.mx-q.mi;
		return res1>res2;
	});
	ll cnt1=0,cnt2=0,cnt3=0;
	vector<node> g;
	for(int i=1;i<=n;i++){
		if(stu[i].mx==stu[i].a){
			if(cnt1<n/2){
				cnt1++;
//				cout<<stu[i].a<<"\n";
				ans+=stu[i].a;
			}
			else{
				g.emplace_back((node){stu[i].b,stu[i].c,1,stu[i].b+stu[i].c,max(stu[i].b,stu[i].c)});
			}
		}
		else if(stu[i].mx==stu[i].b){
			if(cnt2<n/2){
				cnt2++;
				ans+=stu[i].b;
//				cout<<stu[i].b<<"\n";
			}
			else{
				g.emplace_back((node){stu[i].a,stu[i].c,2,stu[i].a+stu[i].c,max(stu[i].a,stu[i].c)});
			}
		}
		else{
			if(cnt3<n/2){
				cnt3++;
				ans+=stu[i].c;
//				cout<<stu[i].c<<"\n";
			}
			else{
				g.emplace_back((node){stu[i].a,stu[i].b,3,stu[i].b+stu[i].a,max(stu[i].b,stu[i].a)});
			}
		}
	}
//	cout<<"\n";
	sort(g.begin(),g.end(),[](node p,node q)->bool{
		ll res1=2*p.mx-p.sum;
		ll res2=2*q.mx-q.sum;
		return res1>res2;
	});
	for(auto i:g){
		if(i.c==1){
			if(i.a==i.mx){
				if(cnt2<n/2){
					cnt2++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
				else{
					cnt3++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
			}
			else{
				if(cnt3<n/2){
					cnt3++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
				else{
					cnt2++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
			}
		}
		else if(i.c==2){
			if(i.a==i.mx){
				if(cnt1<n/2){
					cnt1++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
				else{
					cnt3++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
			}
			else{
				if(cnt3<n/2){
					cnt3++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
				else{
					cnt1++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
			}
		}
		else{
			if(i.a==i.mx){
				if(cnt1<n/2){
					cnt1++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
				else{
					cnt2++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
			}
			else{
				if(cnt2<n/2){
					cnt2++;
					ans+=i.b;
//					cout<<i.b<<"\n";
				}
				else{
					cnt1++;
					ans+=i.a;
//					cout<<i.a<<"\n";
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/
