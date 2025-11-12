#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
map<pair<string,string>,int>mpp;
int specheck=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		string sa,sb;
		cin>>sa>>sb;
		mp[sa]=sb;
		mpp[make_pair(sa,sb)]++;
		if(sa==sb)specheck++;
	}
	if(q==1||q<=100){	
		for(int i=1;i<=q;i++){
			string x,y;
			int ans=0;
			cin>>x>>y;
			string e="";
			for(int i=0;i<x.size();i++)
				for(int j=i+1;j<x.size();j++){
					for(int k=i;k<=j;k++)e+=x[k];
					if(mp.find(e)!=mp.end()){
						string p=x;
						//cout<<"p1:"<<p<<endl;
						for(int k=i;k<=j;k++)p[k]=mp[e][k-i];
						//cout<<"p2:"<<p<<endl;
						if(p==y)ans+=mpp[make_pair(e,mp[e])];
					}
					e="";
				}
			cout<<ans<<endl;
		}
	}
	else{
		for(int i=1;i<=q;i++){
			string x,y;
			int ans=0;
			cin>>x>>y;
			int ta,tb;
			for(int j=0;j<x.size();j++)if(x[j]=='b')ta=j;
			for(int j=0;j<y.size();j++)if(y[j]=='b')tb=j;
			string ax="b",bx="b";
			for(int i=1;i<=tb-ta;i++){
				if(ta<tb)
					ax+="a",bx="a"+bx;
				if(ta>tb)
					ax="a"+ax,bx+="a";
			}
			if(ta!=tb){
				ans=mpp[make_pair(ax,bx)];
				cout<<ans<<endl;
			}
			else cout<<specheck<<endl;
		}
	}
	return 0;
}
