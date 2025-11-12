#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool vis[500005];
//long long ans;
struct node{
	int x,y,z;
};
vector<node> v,ans;
bool cmp(node x,node y){
	if(x.z!=y.z) return x.z<y.z;
	return x.x<y.x;
}
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((a[i]^a[j-1])==k){
				v.push_back({j,i,i-j+1});
			}
		}
	}sort(v.begin(),v.end(),cmp);
	long long vz=v.size();
	for(int i=0;i<vz;i++){
		if(i==0){
			ans.push_back({v[0].x,v[0].y});
			continue; 
		}int xi=ans[ans.size()-1].x,yi=ans[ans.size()-1].y;
		if(v[i].x>=xi && v[i].y<=yi || v[i].x>=xi && v[i].x<=yi || v[i].y>=xi && v[i].y<=yi) continue;
		ans.push_back({v[i].x,v[i].y});
	}for(int i=0;i<ans.size();i++) cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	cout<<ans.size()-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
