#include<bits/stdc++.h>
using namespace std;
int n,m,lr,lrl,c,r,stl,st_a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int st[n*m];
	for(int i = 0;i < n*m;i ++){
		cin >> st_a[i];
		stl ++;
	} 
	lr = st_a[0];
	sort(st_a,st_a + stl);
	for(int i = 0;i < stl;i ++){
		st[i] = st_a[stl - i - 1];
		if(st[i] == lr){
			lrl = i + 1;
		}
	} 
	if(lrl % n == 0) c = lrl / n;
	else c = lrl / n + 1;
	if(c % 2 == 0){
		if(lrl % n == 0) r = 1;
		else r = n + 1 - lrl % n;
	}else{
		if(lrl % n == 0) r = n;
		else r = lrl % n;
	} 
	cout << c << " " << r;
	return 0;
}