#include<bits/stdc++.h>
using namespace std;
int n , m;
int r;
int pai;
int student[1000];
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> student[i];
		if(i == 1) r = student[i];
	} 
	
	sort(student + 1, student + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(student[i] == r) {
			pai = i;
			break;
		}
	}
	if(pai == n){
		cout << 1 << " " << n;
		return 0;
	}
	if(pai < n){
		cout << 1 << " " << pai % n;	
	} else{
		int p = pai / n;
		if(p % 2 == 1) cout << p + 1 << " " <<  n - (pai - n * p) + 1;
		else cout << p + 1 << " " << pai % n;
	}
	return 0;
}