#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[105];
int main(){
	freopen("seat.in","r","stdin")
	freopen("seat.out","w","stdout")
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	a[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int l=0,r=1,t=0;
	for(int i=1;i<=m;i++){
		l++;
		for(int j=1;j<=n;j++){
			t++;
			if(i%2==1){
				r=j;
			}else{
				r=n-j+1;
			}
			if(a[t]==R){
				cout<<l<<' '<<r;
				return 0;
			}
		}
		
	}
	return 0;
}
