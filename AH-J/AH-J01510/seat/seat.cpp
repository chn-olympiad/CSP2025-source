#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,csp[20][20],ansx,ansy,k;
struct stu{
	int order,grade;
}a[120];
bool cmp(stu x,stu y){
	return x.grade>y.grade;
}
void dfs(int x,int y,char c,int step){
	csp[x][y]=a[step].grade;
	if(step>k) return;
	if(a[step].order==1){
		ansx=x,ansy=y;
	}
	if(c=='d'){
		if(x<n) x++;
		else y++,c='u';
	}
	else {
		if(x>1) x--;
		else y++,c='d';
	}
	dfs(x,y,c,step+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i].grade;
		a[i].order=i;
	}
	sort(a+1,a+k+1,cmp);
	dfs(1,1,'d',1);
	cout<<ansy<<' '<<ansx; 
	return 0;
}
