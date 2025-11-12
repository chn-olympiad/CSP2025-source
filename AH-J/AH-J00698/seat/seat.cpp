#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rscore,rseat,rx,ry;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	rscore=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==rscore){
			rseat=i;
			break;
		}
	}
	rx=rseat/n+1;
	ry=rseat%n+1;
	if(rx%2==0)ry=n+1-ry;
	cout<<rx<<' '<<ry<<endl;
	return 0;
}
