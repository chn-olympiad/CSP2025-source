#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[15][15];
	int b[105],c;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+1+n*m,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(b[i]==c){
			x=i;
			break;
		}
	}
	int i=0;
	while(i*n<x){
		i++;
	}
	cout<<i<<" ";
	x-=(i-1)*n;
	if(i%2==0){
		cout<<n-x+1;
	}
	else cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
