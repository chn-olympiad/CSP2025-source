#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int a[105];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int len = n * m;
	for(int i = 1;i <= len;i++){
		cin >> a[i];
	}
	t = a[1];
	sort(a+1,a+len+1,cmp);
	for(int i = 1;i <= len;i++){
		if(t == a[i]){
			t = i;
			break;
		}
	}
	int x, y;
	x = t / n;
	y = t % n;
	if(y != 0){
		x++;
		if(x%2==0){
			y = n - y + 1;
		}
	}else{
		y = n;
	}
	cout << x << " " << y << endl;
	return 0;
}
