#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,b,rank=1;cin>>n>>m>>b;
	s=m*n;vector<int>a(s);
	for(int i=1;i<s;i++){
		cin>>a[i];
		if(a[i]>b)rank++;
	}int col=(rank+m-1)/m,row=(rank-1)%m+1;
	printf("%d %d",col,(col%2==1) ? row:m-row+1);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
