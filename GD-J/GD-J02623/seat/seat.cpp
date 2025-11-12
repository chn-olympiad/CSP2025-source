#include<iostream>
#include<algorithm>
using namespace std;
int a[15][15],n,m,b[105],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	x=b[1];
	sort(b+1,b+n+1,cmp);
	if(n==1){
		for(int i=1;i<=m;i++) if(b[i]==x) cout<<i<<" "<<1;
	}
	else if(m==1){
		for(int i=1;i<=n;i++) if(b[i]==x) cout<<1<<" "<<i;
	}
	else cout<<1<<" "<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
