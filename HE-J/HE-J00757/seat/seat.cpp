#include <bits/stdc++.h>
using namespace std;
int n,m,ar,x,w,y;
int a[105];
int mp[20][20];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ar){
			w=i;
		}
	}
	int z=w/m;
	if(w%m!=0){
		z+=1;
	}
	if(z%2==0){
		if(w%m==0){
			y=1;
		}else{
			y=m-w%m+1;
		}
	}else{
		if(w%m==0){
			y=m;
		}else{
			y=w%m;
		}
	}
	cout<<z<<" "<<y;
	return 0;
}
