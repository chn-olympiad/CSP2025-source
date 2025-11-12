#include<bits/stdc++.h>
using namespace std;
int a[105];
int r;
int n,m;
int mn;
int xn,yn;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) mn=i;
	}
	yn=mn%n;
	if(yn==0) yn=4;
	xn=(mn-1)/n+1;
	if(xn%2!=0){
		cout<<xn<<" "<<yn;
	}else{
		cout<<xn<<" "<<5-yn;
	}
	return 0;
}

