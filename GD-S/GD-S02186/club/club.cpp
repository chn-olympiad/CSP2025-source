#include<bits/stdc++.h>
using namespace std;
int arr[200005][3];
int n;
int dfs(int x , int sum , int a , int b , int c){
	if(x>=n) return sum;
	int g1 = 0 , g2 = 0 , g3 = 3;
	if(a < n/2) g1 = dfs(x+1 , sum + arr[x][0] , a+1 , b , c);
	if(b < n/2) g2 = dfs(x+1 , sum + arr[x][1] , a , b+1 , c);
	if(c < n/2) g3 = dfs(x+1 , sum + arr[x][2] , a , b , c+1);
	return max(max(g1,g2),g3);
}
void man(){
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	cout << dfs(0,0,0,0,0) << '\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int x;
	cin >> x;
	while(x--) man();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
