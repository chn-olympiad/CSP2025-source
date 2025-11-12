#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],p[500007],s=0,col[500007],cs=0,c[500007];
map<int,vector<int> >mp;
vector<pair<int,int> > x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
		mp[p[i]].push_back(i);
	}
	for(int i=0;i<=n;i++){
		if(!mp[k^p[i]].empty()){
			for(auto j:mp[k^p[i]]){
				if(j<i+1) continue;
				x.push_back({i+1,j});
				bool flag=0;
				s++;
//				for(int k=i+1;k<=j;k++){
//					col[k]++;
//					if(col[k-1]<col[k]){
//						cs+=max(0,col[k]-col[k-1]);
//						c[x.size()-1]+=max(0,col[k]-col[k-1]);
//					}
//				}
			}
		}
	}
//	for(auto i:x){
//		cout<<i.first<<" "<<i.second<<endl;
//	}
	cout<<s;
	return 0;
} 
