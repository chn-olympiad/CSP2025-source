#include <bits/stdc++.h>
using namespace std;

const int MAXn = 1e5+5;

struct Node{
	int n,x,y;
}b[MAXn*4];

bool cmp1(int a,int b){
	return a > b;
}
bool cmp(Node a,Node b){
	return a.n > b.n;
}

bool used[MAXn];
int d[MAXn];
int a[MAXn][4];
int t,n,ans=0;

bool sp1(){
	for (int i=1;i<=n;i++)
		if (a[i][1] != 0) return false; 
	for (int i=1;i<=n;i++)
		if (a[i][2] != 0) return false; 
	return true;
}
bool sp2(){
	for (int i=1;i<=n;i++)
		if (a[i][2] != 0) return false; 
	return true;
}

int dfs(int p,int sum,int c1,int c2,int c3){
	if (p > n) return sum;
	
	if (c1==n/2){
		if (a[p][2]>a[p][3]){
			return max(ans,dfs(p+1,sum+a[p][2],c1,c2+1,c3));
		}else{
			return max(ans,dfs(p+1,sum+a[p][3],c1,c2,c3+1));
		}
	}else if (c2==n/2){
		if (a[p][1]>a[p][3]){
			return max(ans,dfs(p+1,sum+a[p][1],c1+1,c2,c3));
		}else{
			return max(ans,dfs(p+1,sum+a[p][3],c1,c2,c3+1));
		}
	}else if (c3==n/2){
		if (a[p][1]>a[p][2]){
			return max(ans,dfs(p+1,sum+a[p][1],c1+1,c2,c3));
		}else{
			return max(ans,dfs(p+1,sum+a[p][2],c1,c2+1,c3));
		}
	}
		
	int ans=0;
	for (int i=1;i<=3;i++){
		if (i==1 && c1==n/2) continue;
		if (i==2 && c2==n/2) continue;
		if (i==3 && c3==n/2) continue;
		if (i == 1)
			ans = max(ans,dfs(p+1,sum+a[p][i],c1+1,c2,c3));
		if (i == 2)
			ans = max(ans,dfs(p+1,sum+a[p][i],c1,c2+1,c3));
		if (i == 3)
			ans = max(ans,dfs(p+1,sum+a[p][i],c1,c2,c3+1));
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while (t--){ 
	
	int len=0,ans=0;
	int count[4]={0,0,0,0};
	cin>>n;
	for (int i=1;i<=n;i++){
		used[i] = false;
		for (int j=1;j<=3;j++){
			cin>>a[i][j];
			b[len+1].n = a[i][j];
			b[len+1].x = i;
			b[len+1].y = j-1;
			len++;
		}
	}
	
	if (sp1()){
		for (int i=1;i<=n;i++)
	 		d[i] = a[i][0];
		sort(d+1,d+n+1,cmp1);
		for (int i=1;i<=n/2;i++)
			ans += d[i];
		cout<<ans<<endl;
		continue;
	}
	
	if (n<=25){
		cout<<dfs(1,0,0,0,0)<<endl;
		continue;
	}
	
	sort(b+1,b+len+1,cmp);
	
	int cnt=0,idx=1;
	while (cnt < n){
		Node tmp = b[idx++];
		if (used[tmp.x]) continue;
		if (count[tmp.y] >= n/2) continue;
		used[tmp.x] = true;
		count[tmp.y]++;
		ans += tmp.n;
		cnt++;
	}
	
	cout<<ans<<endl;
	
	
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
