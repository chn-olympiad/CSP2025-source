#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
priority_queue<int> q;
int n , m;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	int ans;
	cin >> ans;
	q.push(ans);
	for(int i = 2 ; i <= n * m ; i ++){
		int t;
		cin >> t;
		q.push(t);
	}
	int h = 1;
	int l = 1;
	bool hqt = false;//false代表向下走，true代表向上走	
	while(!q.empty()){
		int num = q.top();
		q.pop();
		if(num == ans){
			cout << l << " " << h;
			exit(0);
		}
		if(h == n && !hqt){
			l ++;
			hqt = true;
		}else if(h == 1 && hqt){
			l ++;
			hqt = false;
		}else if(hqt){
			h --;
		}else{
			h ++;
		}
	}
	return 0;
} 
