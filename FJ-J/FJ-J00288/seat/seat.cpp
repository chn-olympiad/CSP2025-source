#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
int n,m,a[N],p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;;i++){
		if(a[i]==tmp){
			break;
		}
		if(y%2){
			if(x+1<=n)x++;
			else y++;
		}else{
			if(x-1>=1)x--;
			else y++;
		}
	}
	return 0;
}
