#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int a[5005];
struct node{
	int m,p,c;
};
queue<node>q;
void bfs(){
	q.push({1,a[1],1});
	while(!q.empty()){
		node cur = q.front();
		for(int i = cur.m+1;i <= n;i++){
			q.push({i,cur.p+a[i],cur.c+1});
			cout << cur.m << " " << cur.p << " " << cur.c << endl;
			if(cur.c >= 3 && cur.p >  a[i]){
				ans++;	
			}
		}
		q.pop();
	}
}
int main(){
	//freopen("r","polygon.in",stdin);
	//freopen("W","polygon.out",stdout);
	cin >> n;
	if(n == 3){
		int a ,b,c;
		cin >> a >> b >> c;
		if((a+b)>c&&(b+c)>a&&(a+c)>b){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	bfs();
	cout << ans % 998244353;
}
