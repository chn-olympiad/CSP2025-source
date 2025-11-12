#include<bits/stdc++.h>
using namespace std;
int n,m,score;
int a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&score);
	int rank = 1;
	for(int i = 2; i <= n*m; i++){
		scanf("%d",a + i);
		if(a[i] > score) rank++; 
	}
	
	pair<int,int> ans;
	ans.first = ceil((double)rank / n * 1.0);
	ans.second = (ans.first % 2) ? (rank - n * (ans.first - 1)) : (n * (ans.first - 1));
	printf("%d %d",ans.first,ans.second);
	return 0;
}
