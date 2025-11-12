#include<bits/stdc++.h>
using namespace std;
int k[1005],n,m,cnt,p,x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>cnt;
    k[1]=cnt;
    for(int i=2;i<=n*m;i++){
		cin>>k[i];
	}
	sort(k+1,k+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(k[i]==cnt){
			p=i;
			break;
		}
	x=p/n+1,y=p%n;
	if(y==0){
		x--;
		if(x%2==1)y=n;
		else y=1;
	}
	else if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
    return 0;
}
