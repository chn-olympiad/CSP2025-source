#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
short grade[101];
bool cmd(short a,short b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,s,i,k;
	cin >> n >> m;
	s=n*m;
	cin >> k;
	grade[0]=k;
	for(i=1;i<s;i++)cin >> grade[i];
	sort(grade,grade+s,cmd);
	for(i=0;i<s&&grade[i]!=k;i++);
	cout << i/n+1 << ' ' << (i/n+1&1?i%n+1:m-i%n);
	return 0;
}
