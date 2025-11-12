#include<bits/stdc++.h>
using namespace std;
int a[110],top=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int heng;
	int shu;
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]) top++;
	}
	int y=0;
	if(top>n) y=top%n;
	else y=top;
	shu=(top/n);
	if(shu*n!=top) shu++;
	else shu=top/n;
	if(shu%2!=0){
		heng=y;
	}else if(shu%2==0){
		heng=n+y-1;
	}
	cout<<shu<<" "<<heng;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
