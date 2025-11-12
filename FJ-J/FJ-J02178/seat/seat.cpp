#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,now,line,row,cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat,in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tot=n*m;
	for(int i=1;i<=tot;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+tot+1,cmp);
	while(a[cnt]!=k) cnt++;
	now=cnt;
	if(now<=n) line=1;
	else if(now%n==0) line=now/n;
	else line=now/n+1;
	if(line%2==1){
		if(now%n!=0) row=now%n;
		else row=n;
	}
	else if(line%2==0){
		if(now%n!=0) row=n+1-now%n;
		else row=1;
	}
	cout<<line<<' '<<row;
	return 0;
}
