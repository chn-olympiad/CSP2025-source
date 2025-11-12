#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	int a[1001];
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++)cin >> a[i];
	int num = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1 ; i <= n * m ; i++)
		if(a[i] == num)num = i;
	int i = 1, j = 1;
	if(num % n == 0)i = num / n;
	else i += num / n;
	if(i % 2 == 1){
		if(num % n == 0)j = n;
		else j = num % n;
	}
	else{
		if(num % n == 0)j = 1;
		else j = n - (num % n) + 1;
	}
	cout << i << " " << j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

