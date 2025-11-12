#include <bits/stdc++.h>
using namespace std;
const int MAX_N=15;
int n,m,a[MAX_N*MAX_N];
int pos,f,cnt=0;
bool cmp(int x,int y){return x>y;}
void ch(){
	if(f==1) f=-1;
	else f=1;
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	sort(a+1,a+1+n*m,cmp);
	f=1;
	int i=1;
	for(int j=1;j<=m;j++){
		for(;;i+=f){
			cnt++;
			if(a[cnt]==pos){
				cout<<j<<" "<<i;
				return 0;
			}
			if((f==1&&i==n)||(f==-1&&i==1)){
				ch();
				break;
			}
		}
	}
	return 0;
}