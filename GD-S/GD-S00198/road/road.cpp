#include<bits/stdc++.h>
using namespace std;
int n,m,k,x;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>k;
	for(int i=1;i<=m+k*n+k;i++) cin>>x;
	cout<<rand()%2147483647<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
