#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,a[N][N],all[N*N],y=1,x=1,k;
bool f=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>all[i];
	k=all[1],sort(all+1,all+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(all[i]==k){
			cout<<x<<' '<<y;
			break;
		}
		if((!f&&y+1>n)||(f&&y-1<1))x++,f=!f;
		else if(f)y--;
		else y++;
	}
	return 0;
}
