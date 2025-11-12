#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1,lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(k<x) cnt++;
	}
	
	if(cnt%n==0) lie=cnt/n;
	else lie=cnt/n+1;
	if(lie%2==0&&cnt%n==0) hang=1;
	if(lie%2!=0&&cnt%n==0) hang=cnt%n+n;
	if(lie%2==0&&cnt%n!=0) hang=1-cnt%n+n;
	if(lie%2!=0&&cnt%n!=0) hang=cnt%n;
	printf("%d %d\n",lie,hang);
	return 0;
}	
