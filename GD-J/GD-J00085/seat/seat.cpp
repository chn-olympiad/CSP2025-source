#include <bits/stdc++.h>//freopen
using namespace std;
const int N=200;
int n,m,cnt,sl,now,row,col;
struct ppl{
	int num,pos;
}a[N];
bool cmp(ppl a, ppl b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m, cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>a[i].num, a[i].pos=i;
	sl=a[1].num;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i].num==sl){
			now=i;
		}
	}
	if(now%n==0) row=now/n;
	else row=now/n+1;
	if(row%2==1) col=now%n;
	else col=n-now%n+1;
	if(now%n==0&&row%2==1) col=n;
	if(now%n==0&&row%2==0) col=1;
	cout<<row<<' '<<col;
	return 0;	
}
/*
สýังฬโ 
*/
