#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

long long list[106], n, m;
int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	for(int i = 1; i <= n * m; i++){
		cin>>list[i];
	}
	int rr = list[1], xx;
	sort(list + 1, list + 1 + n * m, cmp1);
	for(int i = 1; i <= n * m; i++){
		if(list[i] == rr){
			xx = i;
			break;
		}
	}
	int p, q, i = 0;
	while(1){
		if(xx <= (i + 1) * m && xx >= i * m + 1){
			p = i + 1;
			break;
		}
		i++;
	}
	q = xx % m;
	if(p % 2 == 0){
		q = m - q + 1;
	}
	
	cout<<p<<' '<<q;
	return 0;
} 
