#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int t,v[N];
struct xyz{
	int a,b,c;
}s[N];

struct abc{
	int v,w,id;
};

priority_queue<abc, vector<abc>, greater<abc> > pq1;
priority_queue<abc, vector<abc>, greater<abc> > pq2;
priority_queue<abc, vector<abc>, greater<abc> > pq3;

bool operator>(abc x,abc y){
	return x.v-x.w>y.v-y.w;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		while(!pq1.empty()) pq1.pop();
		while(!pq2.empty()) pq2.pop();
		while(!pq3.empty()) pq3.pop();
		int n;
		cin>>n;
		int x=0,y=0,z=0,ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c; 
			cin>>a>>b>>c;
			if(a>=b && a>=c){
				x++;
				ans+=a;
				if(a-b<a-c)
					pq1.push({a,b,i});
				else 
					pq1.push({a,c,i});
			}
			else if(b>=a && b>=c){
				y++;
				ans+=b;
				if(b-a<b-c)
					pq2.push({b,a,i});
				else
					pq2.push({b,c,i});
			}
			else{
				z++;
				ans+=c;
				if(c-a<c-b)
					pq3.push({c,a,i});
				else
					pq3.push({c,b,i});
			}
			s[i].a=a;
			s[i].b=b;
			s[i].c=c;
		}
		while(x>y+z || y>x+z || z>x+y){
			if(x>y+z){
				abc t=pq1.top();
				pq1.pop();
				x--;
				ans-=t.v;
				int i=t.id;
				if((t.w==s[i].b && y+1<=x+z) || z+1>x+y){
					pq2.push({s[i].b,i});
					y++;
					ans+=s[i].b;
				}
				else{
					pq3.push({s[i].c,i});
					z++;
					ans+=s[i].c;	
				}
			}
			else if(y>x+z){
				abc t=pq2.top();
				pq2.pop();
				y--;
				ans-=t.v;
				int i=t.id;
				if((t.w==s[i].a && x+1<=y+z) || z+1>x+z){
					pq1.push({s[i].a,i});
					x++;
					ans+=s[i].a;
				}
				else{
					pq3.push({s[i].c,i});
					z++;
					ans+=s[i].c;
				}
			}
			else{
				abc t=pq3.top();
				pq3.pop();
				z--;
				ans-=t.v;
				int i=t.id;
				if((t.w==s[i].a && x+1<=y+z) || y+1>x+z){
					pq1.push({s[i].a,i});
					x++;
					ans+=s[i].a;
				}
				else{
					pq2.push({s[i].b,i});
					y++;
					ans+=s[i].b;	
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
