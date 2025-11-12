#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100010;
struct node{
	ll a,b,c;
};

inline bool cmpa(node e,node f){
	return e.a-max(e.b,e.c)<f.a-max(f.b,f.c);
}
inline bool cmpb(node e,node f){
	return e.b-max(e.a,e.c)<f.b-max(f.a,f.c);
}
inline bool cmpc(node e,node f){
	return e.c-max(e.b,e.a)<f.c-max(f.b,f.a);
}
ll t,n,aa,bb,cc,ans;

vector<node> a,b,c;
int main(){
	ios::sync_with_stdio(false);
//	a.clear();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		b.clear();
		c.clear();
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>aa>>bb>>cc;
			if(aa>bb){
				if(aa>cc) a.push_back({aa,bb,cc});
				else c.push_back({aa,bb,cc});
			}
			else{
				if(bb>cc) b.push_back({aa,bb,cc});
				else c.push_back({aa,bb,cc});
			}
		}
		
		if(a.size()>(n/2)){
			sort(a.begin(),a.end(),cmpa);
			for(int i=0;i<a.size()-n/2;i++) ans+=max(a[i].b,a[i].c);
			for(int i=a.size()-n/2;i<a.size();i++){
				ans+=a[i].a;
			}
		}
		else{
			for(int i=0;i<a.size();i++) ans+=a[i].a;
		}
		
		if(b.size()>(n/2)){
			sort(b.begin(),b.end(),cmpb);
			for(int i=0;i<b.size()-n/2;i++) ans+=max(b[i].a,b[i].c);
			for(int i=b.size()-n/2;i<b.size();i++){
				ans+=b[i].b;
			}
			
		}
		else{
			for(int i=0;i<b.size();i++) ans+=b[i].b;
		}
		
		if(c.size()>(n/2)){
			sort(c.begin(),c.end(),cmpc);
			for(int i=0;i<c.size()-n/2;i++) ans+=max(c[i].b,c[i].a);
			for(int i=c.size()-n/2;i<c.size();i++){
				ans+=c[i].c;
			}
		}
		else{
			for(int i=0;i<c.size();i++) ans+=c[i].c;
		}
		
	//	cout<<a.size()<<" "<<b.size()<<" "<<c.size()<<endl;
		cout<<ans<<endl;
		
	}
	
	
	
	return 0;
} 
