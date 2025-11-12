#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],p,cnt;
void solvee(){
	int dir=1,cur=1;
	while(1){
		for(int i=1; i<=m; i++)
			for(int j=cur; ;j+=dir){
				if(a[cnt]==p){
					cout<<i<<' '<<j;
					return;
				}
				cnt--;
				if(j==n-cur+1){
					cur=j,dir*=-1;
					break;
				}
				
			}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	p=a[1];
	cnt=n*m;
	sort(a+1,a+cnt+1);
	solvee();
	return 0;
}
