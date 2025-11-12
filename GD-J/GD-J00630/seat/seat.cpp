#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int rr,pos,hs=1,ls=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	rr=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(hs>n&&(ls&1))ls++,hs=n;
		if(hs<1&&(ls%2==0))ls++,hs=1;
		if(a[i]==rr){
			break;
		}
		if(ls&1)hs++;
		else hs--;
	}
	cout<<ls<<" "<<hs;
}
