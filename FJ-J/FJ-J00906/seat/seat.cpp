#include<bits/stdc++.h>
using namespace std;
int n,m,nm,a[105],s;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	nm=n*m;
	for(int i = 1;i <= nm;i++){
		cin >> a[i];
	}
	int fr = a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i = 1;i <= nm;i++){
		if(a[i] == fr) s = i;
	}
	int i = 1,j = 1;
	while(s--){
		if(s==0) cout << j << ' ' << i;
		if(j%2==1&&i!=n) i++;
		else if(j%2==0&&i!=1) i--;
		else if(i==n||i==1)j++;
	}
	return 0;
}
