

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;


#define ll long long
const ll maxn=1000005;
const ll inf=-1;
ll n,m,k;
vector <vector<ll> > G;
vector <vector<ll> > C;
ll vis[15];
ll ans=0;


void calculate(){
	
	ll check=0;
	for(int i=0;i<k;i++){
			if(C[i][0]!=0){
				check++;
				break;
			}

	}

	if(check==0){
	ll cal=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				//cout<<34534;
				if(G[i][j]==inf)continue;
				else{
					//cout<<324523424111;
					ll pos=G[i][j];
					for(int q=0;q<k;q++){
						//cout<<88888823;
						pos=min(pos,C[q][i]+C[q][j]);
					}
					ans+=pos;
					
				}
				
			}

		}
		cout<<ans;
	}
	else{
		
	}
	
	
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	
	cin>>n>>m>>k;
	for(int i=0;i<n+1;i++){
		vector <ll> tmp;
		for(int j=0;j<n+1;j++){
			
			tmp.push_back(inf);
		}
		G.push_back(tmp);
	}

	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		G[u][v]=w;G[v][u]=w;

	}
	for(int i=0;i<k;i++){
		vector <ll> tmp;
		for(int j=0;j<=n;j++){
			ll c;
			cin>>c;//cout<<c<<endl;
			tmp.push_back(c);
		}
		C.push_back(tmp);
	}
	calculate();
	
	
	return 0;
} 
