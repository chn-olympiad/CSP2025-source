#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,c;
int a[105];
bool cmp(int d,int f){
	return d>f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	int h=1;
	while(a[h]!=c)h++;
	int t=(h-1)/n+1;
	if(t%2==1){
		h-=(t-1)*n;
	}else{
		h-=(t-1)*n;
		h=(n+1)-h;
	}
	cout<<t<<" "<<h;
	
	return 0;
}
/*
priority_queue<int> q;
bool operator<(SS x)
*/
