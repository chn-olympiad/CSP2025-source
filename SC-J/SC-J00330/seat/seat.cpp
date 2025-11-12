#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,c,r,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>x;
	int i=n*m-1;
	while(i--){
		scanf("%d",&y);
		if(y>x)cnt++;
	}
	c=(cnt%n==0)?cnt/n:cnt/n+1;
	if(c%2==0) r=(cnt%n==0)?1:n+1-(cnt%n);
	else r=(cnt%n==0)?n:cnt%n;
	printf("%d %d",c,r);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}