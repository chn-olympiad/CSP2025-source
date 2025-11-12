#include <bits/stdc++.h>
#define int long long
using namespace std;
struct ww{
	int a,b,c;
}v[1000005];
int n;
priority_queue<pair<int,int> > A;
priority_queue<pair<int,int> > B;
priority_queue<pair<int,int> > C;
int o1,o2;
bool cmp(ww l,ww r){
	return max(l.a,max(l.b,l.c))>max(r.a,max(r.b,r.c));
}
signed main1(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i].a>>v[i].b>>v[i].c;
	}
	sort(v+1,v+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(v[i].a>=v[i].b&&v[i].a>=v[i].c){
			A.push({max(v[i].b-v[i].a,v[i].c-v[i].a),i});
			ans+=v[i].a;
		}else if(v[i].b>=v[i].a&&v[i].b>=v[i].c){
			B.push({max(v[i].a-v[i].b,v[i].c-v[i].b),i});
			ans+=v[i].b;
		}else if(v[i].c>=v[i].b&&v[i].c>=v[i].a){
			C.push({max(v[i].a-v[i].c,v[i].b-v[i].c),i});
			ans+=v[i].c;
		}
	}
//	cout<<ans<<' '<<A.size()<<' '<<B.size()<<' '<<C.size()<<endl;
	int uo=0;
	if(A.size()>n/2)uo=1;
	if(B.size()>n/2)uo=2;
	if(C.size()>n/2)uo=3;
	if(uo==1){
		while(A.size()>n/2){
			int i=A.top().second;
			ans+=A.top().first;
			if(v[i].b>v[i].c){
				B.push({v[i].c-v[i].b,i});
			}else{
				C.push({v[i].b-v[i].c,i});
			}
			A.pop();
		}
	}else if(uo==2){
		while(B.size()>n/2){
			int i=B.top().second;
			ans+=B.top().first;
			if(v[i].a>v[i].c){
				A.push({v[i].c-v[i].a,i});
			}else{
				C.push({v[i].a-v[i].c,i});
			}
			B.pop();
		}
	}else if(uo==3){
		while(C.size()>n/2){
			int i=C.top().second;
			ans+=C.top().first;
			if(v[i].b>v[i].a){
				B.push({v[i].a-v[i].b,i});
			}else{
				A.push({v[i].b-v[i].a,i});
			}
			C.pop();
		}
	}
	
//	cout<<ans<<' '<<A.size()<<' '<<B.size()<<' '<<C.size()<<endl;
	if(uo==1){
		while(B.size()>n/2){
			ans+=B.top().first;
			C.push(B.top());
			B.pop();
		}
		while(C.size()>n/2){
			ans+=C.top().first;
			B.push(C.top());
			C.pop();
		}
	}else if(uo==2){
		while(A.size()>n/2){
			ans+=A.top().first;
			C.push(A.top());
			A.pop();
		}
		while(C.size()>n/2){
			ans+=C.top().first;
			A.push(C.top());
			C.pop();
		}
	}else if(uo==3){
		while(A.size()>n/2){
			ans+=A.top().first;
			B.push(A.top());
			A.pop();
		}
		while(B.size()>n/2){
			ans+=B.top().first;
			A.push(B.top());
			B.pop();
		}
	}
	
	cout<<ans<<endl;
	while(!A.empty())A.pop();
	while(!B.empty())B.pop();
	while(!C.empty())C.pop();
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)main1();
	return 0;
}
