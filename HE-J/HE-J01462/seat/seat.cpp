#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[200];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int pos=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cin>>a[pos],pos++;
	}
	pos=n*m;
	int grade=a[1];
	sort(a+1,a+pos+1,cmp);
	for (int i=1;i<=pos;i++){
		if (a[i]==grade){
			pos=i;
			break;
		}
	}
	int linel=0,lineh=0;
	linel=(pos-1)/n+1;
	if (linel%2==0){
		lineh=n-((pos-1)%n);
	}
	else {
		lineh=(pos-1)%n+1;
	}
	cout<<linel<<" "<<lineh;
	return 0;
}
