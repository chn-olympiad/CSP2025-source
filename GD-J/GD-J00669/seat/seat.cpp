#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin >> n >> m;
	int a[105]={};
	int cnt=0;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
		if(i==0) cnt=a[i];
	}
	sort(a,a+n*m,cmp);
	int u=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==cnt){
			u=i;
			break;
		}
	}
	u++;
	int x=(u-1)/m+1;
	int y=u%m;
	if(y==0) y=m;
	if(x%2==0){
		cout << x << " " << m-y+1;
	}
	else{
		cout << x << " " << y;
	}
	return 0;
}
