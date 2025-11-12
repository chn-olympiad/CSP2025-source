#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int c,r;
int cnt=1;
priority_queue <int> q;
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&x);
		if(i==1)a[i][1]=x;
		q.push(x);
	}
	while(q.top()!=a[1][1]){
		cnt++;
		q.pop();
	}
	//cout<<cnt<<endl;
	c=ceil(cnt/n);
	if(cnt%n!=0)c++;
	//cout<<c<<endl;
	if(cnt<=n)r=cnt;
	else if(c%2!=0) r=(cnt%n==0) ? n : cnt%n;
	else r=(cnt%n==0) ? (n-(cnt%n)+1)%n : n-(cnt%n)+1;
	cout<<c<<" "<<r;
	//排行除以n上取整得列，取余n得伪行(奇顺偶逆)
	//逆行求法：数目-顺行+1?
	//e.g 1~8 2 8-2+1=7  4 8-4+1=5 1 8-1+1=8
	fclose(stdin);
	fclose(stdout);
	return 0;
}