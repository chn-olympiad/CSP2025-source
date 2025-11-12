#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn][3];
int c[3];
int n,mc;
int f(int m){
	//cout<<m<<"awa\n";
	if(m-1>n) return 0;
	int res = 0;
	for(int i=0;i<3;i++){
		if(c[i]>mc) continue;
		c[i]++;
		//cout<<m<<" "<<i<<" "<<c[i]<<" "<<a[m-1][i]<<"\n";
		res = max(res, f(m+1)+a[m-1][i]);
		c[i]--;
		//cout<<m<<" "<<i<<" "<<c[i]<<"\n";
	}
	//cout<<"return:"<<res<<"\n";
	return res;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		mc = n>>1;
		cout<<f(1)<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
