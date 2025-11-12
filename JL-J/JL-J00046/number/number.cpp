#include <bits/stdc++.h>
using namespace std;
bool df(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string r;
	cin >> r;	
	int a[r.size()+1];
	int y = 0;
	int k = r.size();
	for(int i = 0;i < k;i++){
		if(r[i] >= '0' && r[i] <= '9'){
			y = y + 1;
			a[y] = r[i] - '0';
		}
	}
	sort(a+1,a+y+1,df);
	for(int i = 1;i <= y;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
