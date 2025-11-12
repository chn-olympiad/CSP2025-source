#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,f;
 }a[200];
int n,m,ansc,ansr,k;
bool cmp(node x,node y){
	return (x.num > y.num);
 }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n * m;i++) {
		cin>>a[i].num;
		a[i].f = i;
	 }
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	 if (a[i].f == 1) {k = i;break;}
	ansc = (k + m - 1) / m;
	if (ansc % 2 == 1) {
		ansr = k % n;
		if (ansr == 0) ansr += n;
	 }
	else ansr = n - k % n + 1;
	cout<<ansc<<" "<<ansr;
	return 0;
 }
