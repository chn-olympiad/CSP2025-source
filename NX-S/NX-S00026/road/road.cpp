#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,m,k;
cin>>n>>m>>k;
vector<vector<int>>map(n,vector<int>(n,0));
long long ans=0;
long long u,v,w;
for(int i=0;i<m;i++){
cin>>u>>v>>w;
map.at(u).at(v)=w;
map.at(v).at(u)=w;
}
int c;
int a[n];
for(int i=0;i<k;i++){
cin>>c;
for(int j=0;j<n;j++)cin>>a[j];
for(int ii=0;ii<k;ii++){
	for(int jj=0;jj<n;jj++){
		int s=c+a[ii]+a[jj];
		if(s<map.at(ii).at(jj)){map.at(ii).at(jj)=s;map.at(jj).at(ii)=s;}
	}
}
}
vector<int>finish;
int minn=1000000001;
int minu,minv;
for(int i=0;i<n;i++){
	for(int j=i;j<i;j++){
		if(i==j)continue;
		if(map.at(i).at(j)<minn){
			minn=map.at(i).at(j);
			minu=i;
			minv=j;
		}
	}
}
finish.push_back(minu);
finish.push_back(minv);
ans+=minn;
map.at(minu).at(minv)=1000000001;
map.at(minv).at(minu)=1000000001;
for(int q=0;q<n-2;q++){
	minn=1000000001;minu=0;minv=0;
	for(int p=0;p<int(finish.size());p++){
		for(int j=0;j<n;j++){
			if(j==finish.at(p))continue;
			if(map.at(p).at(j)<minn){
				minn=map.at(p).at(j);
				minu=p;
				minv=j;
			}
		}
	}
	finish.push_back(minu);
	ans+=minn;
	map.at(minu).at(minv)=1000000001;
	map.at(minv).at(minu)=1000000001;
}
cout<<ans<<endl;
return 0;
}
