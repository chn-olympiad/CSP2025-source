#include<bits/stdc++.h>
using namespace std;
int sc[110];
int n,m;
int R;
bool cmp(int x,int y){
	return x>y;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	R=sc[1];
	//cout<<R<<endl;
	sort(sc+1,sc+n*m+1,cmp);
	int rnk;
	for(int i=1;i<=n*m;i++){
		if(sc[i]==R){
		rnk=i;break;}
	}
	//cout<<rnk<<endl;
	int a=rnk/(2*n),b=rnk%(2*n);
	//cout<<a<<" "<<b;
	int r=1+2*a;
	if(b>n){
		r++;
		b=2*n+1-b;
	}
	int c=b;
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
