#include <bits/stdc++.h>
using namespace std;

priority_queue <int> score;
int n,m;
int c,r;
int tmp;
int l = 0;
int own;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	cin >>own;
	score.push(own);
	for (int i = 1;i <= n*m - 1;i++){
		cin >>tmp;
		score.push(tmp);
	}
	while (score.top() != own){
		score.pop();
		l++;
	}
	l++;
	c= l/m;
	if (l % m != 0){
		c++;
	}
	
	r = l % m;
	if (r == 0){
		r = n;
	}
	if (c % 2 == 0){
		r = n - r + 1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
