#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][5];
int b,c,d;
int ans;
void dfs(int x,int cnt){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	b++;
	if(b<=n/2) dfs(x+1,cnt+a[x][1]);
	b--;
	c++;
	if(c<=n/2) dfs(x+1,cnt+a[x][2]);
	c--;
	d++;
	if(d<=n/2) dfs(x+1,cnt+a[x][3]);
	d--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(0,0);
		cout << ans << endl;
		b=0,c=0,d=0;
		ans=0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

