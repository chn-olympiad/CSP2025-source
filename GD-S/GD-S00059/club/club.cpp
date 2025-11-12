#include<bits/stdc++.h>
#define elif else if
#define ll long long
using namespace std;
ll t,n,aa[114514],bb[114514],cc[114514],ans;
struct node{
	ll a,b,c;
};node q[114514];
bool cmp1(ll e,ll w){
	return max(q[e].b,q[e].c)>max(q[w].b,q[w].c);
}
bool cmp2(ll e,ll w){
	return max(q[e].a,q[e].c)>max(q[w].a,q[w].c);
}
bool cmp3(ll e,ll w){
	return max(q[e].b,q[e].a)>max(q[w].b,q[w].a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--){
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(cc,0,sizeof(cc));
		ans=0;
		cin>>n;for(ll i=0;i<n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			if(q[i].a>=q[i].b&&q[i].a>=q[i].c) aa[++aa[0]]=i,ans+=q[i].a;
			elif(q[i].b>=q[i].a&&q[i].b>=q[i].c) bb[++bb[0]]=i,ans+=q[i].b;
			else cc[++cc[0]]=i,ans+=q[i].c;
		}
		if(aa[0]>n/2){
//			cout<<ans<<endl;
			sort(aa+1,aa+aa[0]+1,cmp1);
//			cout<<aa[0]<<' '<<aa[1]<<' '<<aa[2]<<endl;
			for(ll i=1;i<=aa[0]-n/2;i++){
				if(q[aa[i]].b>q[aa[i]].c) ans+=(q[aa[i]].b-q[aa[i]].a);
				else ans+=(q[aa[i]].c-q[aa[i]].a);
			}
		}
		elif(bb[0]>n/2){
//			cout<<ans<<endl;
			sort(bb+1,bb+bb[0]+1,cmp2);
			for(ll i=1;i<=bb[0]-n/2;i++){
//				cout<<bb[1];
				if(q[bb[i]].a>q[bb[i]].c) ans+=(q[bb[i]].a-q[bb[i]].b);
				else ans+=(q[bb[i]].c-q[bb[i]].b);
			}
		}
		elif(cc[0]>n/2){
			sort(cc+1,cc+cc[0]+1,cmp3);
			for(ll i=1;i<=cc[0]-n/2;i++){
				if(q[cc[i]].a>q[cc[i]].b) ans+=(q[cc[i]].a-q[cc[i]].c);
				else ans+=(q[cc[i]].b-q[cc[i]].c);
			}
		}
		cout<<ans<<endl;
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
