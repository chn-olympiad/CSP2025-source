#include<bits/stdc++.h>
using namespace std;
const int mx = 5e5 + 5;
int a[mx];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, h = 0, xh;
	cin >> n >> k;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] == k){
			h ++;
			if(k <= 1) a[i] = -1;
		}
	}
	for(int i = 1; i < n; i ++){
		if(a[i] < 0) continue;
		for(int j = i; j < n; j ++){
			if(a[j] < 0){
				i = j;
				goto Next;
			}
			if(j == i){
				xh = a[j];
				continue;
			}
			xh = (xh xor a[j]);
			if(xh == k){
				h ++;
				i = j;
				goto Next;
			}
		}
		Next:;
	}
	cout << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}