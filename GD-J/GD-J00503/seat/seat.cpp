#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int m = n*k;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	int u = a[1];
	int w = 0;
	sort(a+1,a+1+m,cmp);
	for(int i = 1;i<=m;i++){
		if(a[i]==u){
			w = i;
			break;
		}
	}
	int y = w/k;
	if(w%k!=0){
		y++;
	} 
	cout<<y<<" ";
	if(y%2==1){
		int x = w%k;
		if(x==0){
			x+=k;
		}
		cout<<x;
	}
	else{
		int x = w%k;
		if(x==0){
			x+=k;
		}
		cout<<n-x+1;
	}
	return 0;
}
