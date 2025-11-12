#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[100000][4],b[100000];
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][0]==a[i][1]) {
				b[i]=1;
			}
			else if(a[i][0]==a[i][2]){
				b[i]=2;
			} 
			else {
				b[i]=3;
			}
		}
		if(n==2){
			if(b[1]==b[2]){
				int x,y,z,w;
				if(b[1]==1){
					x=2;y=3;
				}
				else if(b[1]==2){
					x=1;y=3;
				}
				else {
					x=2;y=1;
				}
				if(b[2]==1){
					z=2;w=3;
				}
				else if(b[2]==2){
					z=1;w=3;
				}
				else{
					z=2;w=1;
				}
				cout << max(a[1][0]+max(a[2][z],a[2][w]),a[2][0]+max(a[1][x],a[2][y])) << endl;
			}
			else cout << a[1][0]+a[2][0]<<endl;
			continue;
		}
		int q[100000];
		for(int i=1;i<=n;i++){
			q[i]=a[i][1];
		}
		sort(q+1,q+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=q[i];
		}
		cout << ans << endl;
	}
}
