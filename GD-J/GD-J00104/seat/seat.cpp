#include <bits/stdc++.h>
using namespace std;

int n, m, s[205], number, people, id;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	number = n * m;
	
	for(int i = 1;i <= number; i++){
		cin >> s[i];
	}
	people = s[1];
	
	sort(s + 1,s + number + 1, cmp);
	
	for(int i = 1;i <= number; i++){
		if(s[i] == people){
			id = i;
			break;
		}
	}
	
	int y = id / n;
	if(id % n == 0){
		if(y % 2 == 0)  cout << y << " " << 1;
		else  cout << y << " " << m;
		
	}else{
		if((y + 1) % 2 == 0)  cout << y + 1 << " " << (n - (id % n) + 1);
		else  cout << y + 1 << " " << (id % n);
	} 
	
	return 0;
}
