#include<iostream>
using namespace std;
const int maxn = 10005;
long long a[maxn], n, m, c = 1, r, l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i <= n*m; i++){
		cin >> a[i];
	}
	long long  y = a[0],x;
	for(int i = 0; i <= n*m; i++){
		for(int j = i; j <= n*m; j++){
			if(a[i]<a[j]){
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	for(int i = 0; i <= n*m; i++){
		if(a[i] == y)
			break;
		c++;
	}
	if(c%m == 0){
		r = c/n;
		l = m;
	}
	else{
		if((c/n+1)%2!=0){
			r = c/n+1;
			l = c%m;
		}
		else{
			r = c/n+1;
			l = m-(c%m-1);
		}
	}
	cout << r << " " << l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
