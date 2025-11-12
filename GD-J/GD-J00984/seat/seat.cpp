#include<bits/stdc++.h>
using namespace std;

int a[101];

bool cmp(int x,int y) {
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m; //n为行数，m为列数 
	cin >> n >> m;
	int sz; sz = n*m;
	for(int i = 1; i <= sz; i++) {
		cin >> a[i];
	}//a[1]为需要查找的成绩 
	
	int ans; ans = a[1];
	
	sort(a+1,a+sz+1,cmp);
	
	int c = 1, r = 1;
	for(int i = 1; i <= sz; i++) {
		if(a[i] == ans) {
			cout << c <<" "<< r;
			return 0;
		}else if(c%2 == 1){
			if(r<n) r++;
			else c++;
		}else if(c%2 == 0){
			if(r>1 || r==n) r--;
			else c++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

