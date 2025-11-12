#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int n,m,a[10005]; // nÐÐmÁÐ 

 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int t = n*m;
	for(int i=0;i<t;i++) cin >> a[i];
	
	if(n==1&&m==1){
		cout << "1 1";
		return 0;
	}
	int rs = a[0],ri;
	sort(a,a+t,cmp);
	
	for(int i=0;i<t;i++)
		if(a[i] == rs) ri = i;
	int x = ri/n+1,y;
	if(x%2 == 1){
		int tmp = (ri - n*(x-1));
		y = tmp + 1;
	}
	else{
		int tmp = (ri - n*(x-1));
		y = n - tmp;
	}
	cout << x << " " << y;
	
	return 0;
}
