#include<bits/stdc++.h>
using namespace std;
	
int n, q;
string ti, tj;
string si[200086], sj[200086];
int dif[200086];

int locsb[200086], difsb[200086];

bool flags = 1, flagt;

bool cek(int x, int y){
	for(int i = 0; i < si[x].size(); i++){
		if(ti[y+i] != si[x][i]) return 0;
		if(tj[y+i] != sj[x][i]) return 0;
	}
	return 1;
}

void sol(){
	flagt = 1;
	int dift = 0;
	long long ans = 0;
	cin >> ti >> tj;
	if(ti.size() != tj.size()){
		printf("0\n");
		return;
	}
	int cnttt1 = 0, cnttt2 = 0;
	for(int i = 0; i < ti.size(); i++){
		if(ti[i] != tj[i]) dift++;
		if(ti[i] == 'b') cnttt1++;
		if(ti[i] != 'b' && ti[i] != 'a') flagt = 0;
		if(tj[i] == 'b') cnttt2++;
		if(tj[i] != 'b' && tj[i] != 'a') flagt = 0;
//		printf("%d*\n", dift);
	}
	if(cnttt1 != 1 || cnttt2 != 1) flagt = 0;
	
	if(flags && flagt){
		int locb, difb;
		
		for(int i = 0; i < ti.size(); i++){
			if(ti[i] == 'b') locb = i;
			if(tj[i] == 'b') difb = i;
		}
		for(int i = 1; i <= n; i++){
			if(ti.size() < si[i].size()) continue;
			if(locb < locsb[i]) continue;
			if(ti.size() - locb < si[i].size() - locsb[i]) continue;
			if(difb - locb != difsb[i] - locsb[i]) continue;
			ans++;
		}
		printf("%d\n", ans);
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(dift != dif[i]) continue;
		if(ti.size() < si[i].size()) continue;
		for(int j = 0; j <= ti.size() - si[i].size(); j++){
			if(cek(i,j)) ans++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	
	for(int i = 1; i <= n; i++){
		cin >> si[i] >> sj[i];
		int cnttt = 0;
		for(int j = 0; j < si[i].size(); j++){
			if(si[i][j] != sj[i][j]) dif[i]++;
			if(si[i][j] == 'b') cnttt++;
			if(si[i][j] != 'b' && si[i][j] != 'a') flags = 0;
		}
		if(cnttt != 1) flags = 0;
	}
	
	if(flags){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < si[i].size(); j++){
				if(si[i][j] == 'b') locsb[i] = j;
			}
			for(int j = 0; j < si[i].size(); j++){
				if(sj[i][j] == 'b') difsb[i] = j;
			}
		}
	}
	
	while(q--){
		sol();
	}
	
	return 0;
}
