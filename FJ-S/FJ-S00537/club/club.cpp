#include<bits/stdc++.h>
using namespace std;
struct xxx{
	long long bm[5];
}a[100005];
long long t,n,m,v1,v2,v3,gjd;
void dfs(long long x,long long zdz){
	if(x>=n){
		if(v1<=gjd&&v2<=gjd&&v3<=gjd){
			m=max(m,zdz);
		}
	}else{
		v1++;
		dfs(x+1,zdz+a[x].bm[1]);
		v1--;
		v2++;
		dfs(x+1,zdz+a[x].bm[2]);
		v2--;
		v3++;
		dfs(x+1,zdz+a[x].bm[3]);
		v3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		m=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].bm[1]>>a[i].bm[2]>>a[i].bm[3];
		}
		gjd=n/2;
		dfs(0,0);
		cout<<m<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
