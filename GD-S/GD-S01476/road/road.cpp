#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

long long n,m,k,res=0,ans=0,ss[10025];
vector <int> h[2];
struct node{
	long long h;
	vector <int> s,t;
}a[10025];


void dfs(int p,int q){
	if(res>=ans) return;
	ss[p]++;
	if(q==n){
		if(ans==0||ans>res) ans=res;
		return;
	}
	long long i,j;
	for(i=1;i<=a[p].s[0];i++){
		if(ss[a[p].s[i]]>0) continue;
		else{
			h[0][0]++;
			h[0].push_back(a[p].s[i]);
	        h[1].push_back(a[p].t[i]);
	        j=h[0][0];
	        while(j>1){
				if(h[1][j]>h[1][j-1]){
					swap(h[1][j],h[1][j-1]);
					swap(h[0][j],h[0][j-1]);
					j--;
				}
				else j=1;
			}
		}
	}
	while(ss[h[0][h[0][0]]]>0){
		h[0].pop_back();
		h[1].pop_back();
		h[0][0]--;
	}
	p=h[0][h[0][0]];
	res+=h[1][h[0][0]];
	h[0].pop_back();
	h[1].pop_back();
	h[0][0]--;
	dfs(p,q+1);
}
void f(int p,int q){
	if(p>k){
		long long i;
		for(i=1;i<=n;i++) ss[i]=0;
		while(h[0][0]>0){
			h[0].pop_back();
			h[1].pop_back();
		}
		h[0][0]++;
		h[0].push_back(a[1].s[1]);
	    h[1].push_back(a[1].t[1]);
		dfs(1,1-q);
	}
	else{
		ss[p+n]=0;
		res+=a[p].h;
		f(p+1,q+1);
		res-=a[p].h;
		ss[p+n]=1;
		f(p+1,q);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long i,j,u,v,w,l,r;
	for(i=1;i<=n+k;i++){
		a[i].s.push_back(0);
		a[i].t.push_back(0);
	}
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].s[0]++;
		a[v].s[0]++;
		l=a[u].s[0];
		r=a[v].s[0];
		a[u].s.push_back(v);
		a[v].s.push_back(u);
		a[u].t.push_back(w);
		a[v].t.push_back(w);
		while(l>1){
			if(a[u].t[l]<a[u].t[l-1]){
				swap(a[u].s[l],a[u].s[l-1]);
				swap(a[u].t[l],a[u].t[l-1]);
				l--;
			}
			else l=0;
		}
		while(r>1){
			if(a[v].t[r]<a[v].t[r-1]){
				swap(a[v].s[r],a[v].s[r-1]);
				swap(a[v].t[r],a[v].t[r-1]);
				r--;
			}
			else r=0;
		}
	}
	for(i=1;i<=k;i++){
		cin>>a[i].h;
		for(j=1;j<=n;j++){
			cin>>w;
			v=j;
			u=n+i;
			a[u].s[0]++;
		    a[v].s[0]++;
		    l=a[u].s[0];
		    r=a[v].s[0];
		    a[u].s.push_back(v);
		    a[v].s.push_back(u);
		    a[u].t.push_back(w);
		    a[v].t.push_back(w);
		    while(l>1){
		    	if(a[u].t[l]<a[u].t[l-1]){
		    		swap(a[u].s[l],a[u].s[l-1]);
		    		swap(a[u].t[l],a[u].t[l-1]);
		    		l--;
		    	}
		    	else l=0;
	    	}
		    while(r>1){
			    if(a[v].t[r]<a[v].t[r-1]){
			    	swap(a[v].s[r],a[v].s[r-1]);
			    	swap(a[v].t[r],a[v].t[r-1]);
			    	r--;
			    }
			    else r=0;
		    }
		}
	}
	
	h[0].push_back(0);
	h[1].push_back(0);
	f(1,0);
	
	cout<<ans;
	
	/*for(i=1;i<=n;i++){
		cout<<i<<" "<<a[i].s[0]<<"\n";
		for(j=1;j<=a[i].s[0];j++) cout<<a[i].s[j]<<" ";
		cout<<"\n";
		for(j=1;j<=a[i].s[0];j++) cout<<a[i].t[j]<<" ";
		cout<<"\n\n";
	}*/
	return 0;
}
