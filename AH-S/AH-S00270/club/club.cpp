#include<bits/stdc++.h>
using namespace std;
struct Club{
	int x, y, z;
}a[100001];
int b[4], n, maxx;
void dfs(int m,int sum){
	if(m>n){
		if(sum>maxx){
			maxx=sum;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(b[i]+1<=n/2){
			b[i]++;
			if(i==1){
				dfs(m+1,sum+a[m].x);
			}else if(i==2){
				dfs(m+1,sum+a[m].y);
			}else{
				dfs(m+1,sum+a[m].z);
			}
			b[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t ;
	while(t--){
		maxx=0;
		cin >> n ;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z ;
		}
		b[1]=0;
		b[2]=0;
		b[3]=0;
		dfs(1,0);
		cout << maxx << endl ;
	}

	return 0;

}
