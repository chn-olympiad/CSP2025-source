#include<bits/stdc++.h>

using namespace std;

int n,m,k;
long long u[10100],v[10100],w[10100];
long long c[10100],a[10100][10100];
long long lj[10001];
int used[10100];
int id;
int MIN;
int answer = 0;

int seed = 88888888;

int sj(int seed){
	unsigned int c = pow(2,31);
	return (seed*213014+251101) % c;
}

bool check(){
	for(int i = 0 ; i < n ; i++){
		if(!lj[i]){
			return false;
		}
	}return true;
}

int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++){
		cin >> u[i] >> v[i] >> w[i];
	}for(int i = 0 ; i < k ; i++){
		cin >> c[i];
		for(int j = 0 ; j < n ; j++){
			cin >> a[i][j];
		}
	}
	if(k == 0){
		for(int i = 0 ; i < m ; i++){
			if(u[i] != v[i] && MIN > w[i]){
				id = i;
				MIN = w[i];
			}
		}lj[u[id]] = true;
		used[id] = true;
		lj[v[id]] = true;
		used[id] = true;
		answer += w[id];
		while(check()){
			for(int i = 0 ; i < m ; i++){
				if((lj[v[i]] || lj[u[i]]) && !used[i]){
					lj[v[i]] = true;
					lj[u[i]] = true;
					used[i] = true;
					answer += w[i];
					
				}
			}
		}cout << answer;
	}else{
		int mc = 0;
		for(int i = 0 ; i < m ; i++){
			mc += w[i];
		}for(int i = 0 ; i < k ; i++){
			mc += c[i]/2;
			for(int j = 0 ; j < n ; j++){
				mc += a[i][j]%10*2;
			}
		}
		cout << (sj(seed+mc%sj(mc))+mc)%mc+sj(mc)%1000;
	}
	return 0;
}
