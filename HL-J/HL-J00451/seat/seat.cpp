#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int n,m,tot,rscore,rpos;
int a[N];
int row,line;
bool cmp(int x,int y) {
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++)
		cin>>a[i];
	rscore=a[1];
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		if(a[i]==rscore) {rpos=i; break;}
	
	if(rpos % n == 0) {
		cout<<rpos/n<<' ';
		row=rpos/n;
	}else {
		cout<<rpos/n+1<<' ';
		row=rpos/n+1;
	}
	if(row % 2 == 0) {
		cout<<1+n*row-rpos;
	}else {
		cout<<n-n*row+rpos;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
