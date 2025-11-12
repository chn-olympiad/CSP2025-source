#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tmp=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++tmp];
		}
	}
	int R=a[1];
	sort(a+1,a+tmp+1,cmp);
	bool flag=0;
	int ansx,ansy,nowx=1,nowy=1,now=1;
	while(1){
		if(a[now]==R){
			ansx=nowx,ansy=nowy;
			break;
		}
		if(!flag){
			nowx++;
			if(nowx>n){
				nowx=n,nowy++,flag=1;
			}
		}else if(flag){
			nowx--;
			if(nowx<1){
				nowx=1,nowy++,flag=0;
			}
		}
		now++;
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}
