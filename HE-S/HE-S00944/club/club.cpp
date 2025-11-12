#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

long long t,n,limit,manyi=0,manyi2 =0,tim=0;
int a[N][3];
int li[3] = {0,0,0};

void dfs(int x){//太可怕了，超长time，几分钟都解不出来，dfs你值得拥有！ 
	if(x == n){
		manyi2 = max(manyi,manyi2);
		//cout << "log"<< t <<' '<< tim++<<'\n';
		return;
	}
	for(int i=0;i<3;i++){
		if(li[i]==limit) continue;
		li[i]++;
		manyi += a[x][i];
		dfs(x+1);
		li[i]--;
		manyi -= a[x][i];
		//cout << "bb" <<' '<< x <<'\n';
	}
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t-->0){
		manyi =0;manyi2 =0;
		
		cin >> n;
		limit = n/2;
		
		for(int i=0;i<n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		
	dfs(0);
		
	cout << manyi2<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
