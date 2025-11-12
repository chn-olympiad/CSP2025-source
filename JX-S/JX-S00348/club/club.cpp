#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int T;
int n;
struct P{
	int a,b,c;
}p[100005];

vector<int> v[5];// No.i's people's mark

bool cmpa(int x,int y){return p[x].a>p[y].a;}
bool cmpb(int x,int y){return p[x].b>p[y].b;}
bool cmpc(int x,int y){return p[x].c>p[y].c;}

int main(){
	freopen("mulsum.in","r",stdin);
	freopen("mulsum.out","w",stdout);
	cin>>T;
	while(T--){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c) v[1].push_back(i);
			else if(p[i].b>=p[i].c&&p[i].b>=p[i].a) v[2].push_back(i);
			else v[3].push_back(i);
		}
		
		if((int)v[1].size()>n/2){
			sort(v[1].begin(),v[1].end(),cmpa);		
			for(int i=v[1].size();i>n/2;i--){
				if(p[v[1][i]].b>p[v[1][i]].c){
					v[2].push_back(v[1][i]);
					v[1].pop_back();
				}
				else{
					v[3].push_back(v[1][i]);
					v[1].pop_back();
				}
			}
		}else if((int)v[2].size()>n/2){
			sort(v[2].begin(),v[2].end(),cmpb);
			for(int i=v[2].size();i>n/2;i--){
				if(p[v[2][i]].a>p[v[2][i]].c){
					v[1].push_back(v[2][i]);
					v[2].pop_back();
				}
				else{
					v[3].push_back(v[2][i]);
					v[2].pop_back();
				}
			}
		}else if((int)v[3].size()>n/2){
			sort(v[3].begin(),v[3].end(),cmpc);
			for(int i=v[3].size();i>n/2;i--){
				if(p[v[3][i]].a>p[v[3][i]].b){
					v[1].push_back(v[3][i]);
					v[3].pop_back();
				}
				else{
					v[2].push_back(v[3][i]);
					v[3].pop_back();
				}
			}
		}
		ll sum=0;
		for(auto it:v[1]) sum+=p[it].a;
		for(auto it:v[2]) sum+=p[it].b;
		for(auto it:v[3]) sum+=p[it].c;
		cout<<sum<<'\n';
	}
	return 0;
}
	
