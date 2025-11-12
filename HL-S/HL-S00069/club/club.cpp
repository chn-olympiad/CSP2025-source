#include<bits/stdc++.h>
#define re register
using namespace std;
struct Node{
	int mx,ch;
};
bool cmp(Node x,Node y){
	return x.ch>y.ch;
} 
void solve(){
    int n;
	re long long ans=0;
    scanf("%d",&n);
    vector<vector<int>> v(n+1,vector<int>(4,0));
    vector<Node> v2[4];
    for(re int i=1;i<=n;i++){
    	scanf("%d%d%d",&v[i][1],&v[i][2],&v[i][3]);
    	ans+=max(v[i][1],max(v[i][2],v[i][3]));
	}
	for(re int i=1;i<=n;i++){
	    if(v[i][1]>=v[i][2]&&v[i][1]>=v[i][3]){
	    	v2[1].push_back({v[i][1],v[i][1]-max(v[i][2],v[i][3])}); 
		}
		else if(v[i][2]>=v[i][1]&&v[i][2]>=v[i][3]){
	    	v2[2].push_back({v[i][2],v[i][2]-max(v[i][1],v[i][3])}); 
	    	//cout<<v[i][2]-max(v[i][1],v[i][3]);
		}
		else if(v[i][3]>=v[i][1]&&v[i][3]>=v[i][2]){
	   	    v2[3].push_back({v[i][3],v[i][3]-max(v[i][2],v[i][1])}); 
		}
	}
	vector<Node> v3;
	if(v2[1].size()>n/2){
		v3=v2[1];
	}
	else if(v2[2].size()>n/2){
		v3=v2[2];
	}
	else if(v2[3].size()>n/2){
		v3=v2[3];
	}
	sort(&v3[0],&v3[v3.size()],cmp);
	for(re int i=n/2;i<v3.size();i++){
//		cout<<v3[i].ch<<" "; 
		ans-=v3[i].ch; 
	}
	cout<<ans; 
	cout<<"\n"; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) solve(); 
	return 0;
} 
