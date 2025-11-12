#include<bits/stdc++.h>
using namespace std;
		int n;
struct D
{
	int i,ix;
};
queue<D>q;
void ss(int mx,D g)
{
	if(!q.empty()){
		auto d=q.top();q.pop();
		int i=d.i, ix=d.ix;
		if(f[a[j].ix]>mx){
			int ma=-2e9;
			for(int i=1;i<=3;i++){
				ma=max(ma,f[a[j].i]);
			}
			if(f[a[j].ix]>ma){
						
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)
	{
		vector<int>f(4,0);
		cin>>n;
		vector<D>c(n,0);
		int mx=n/2;
		vector<D>a(3,{0});
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j].i;
				a[j].ix = j+1;
			}
			sort(a.begin(),a.end(),[](const D &q,const D &p){
				return q.i>=p.i;
			});
			map<D,int>mp;
			for(int j=0;j<3;j++){
				if(f[a[j].ix]>mx){
					int ma=-2e9;
					for(int k=1;k<=3;k++){
						ma=max(ma,f[a[j].i]);
					}
					if(f[a[j].ix]>ma){
						f[]
					}
				}
				else{
					++f[a[j].ix];
					mp[a[j]]=
				}
			}
			
		} 
		
		
	}
	
	return 0;
} 
