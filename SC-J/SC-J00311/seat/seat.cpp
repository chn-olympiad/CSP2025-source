#include<bits/stdc++.h>
using namespace std;

int n, m, r, cnt=0;
priority_queue <int> pq;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "r", stdout);
	
	cin >> n >> m;
	cin >> r;
	pq.push(r);
	for(int i = 1; i < n*m; i++){
		int tmp; cin >> tmp;
		pq.push(tmp);
	}
	for(int i = 0; i < n*m; i++){
		cnt++;
		if(pq.top() == r){
//			int Row = cnt/n;//行;
//			int Col;//列； 
//			cout <<"row:"<<Row<<endl;
//			if(cnt%n != 0){
//				Row ++;
//			}
//			
//			if(Row%n == 1) Col = cnt%n;
//			else Col = n - cnt%n + 1;
//			if(Col == 0) Col = n;
//			cout << Row << ' ' << Col;
			int Col, Row;
			Col = (cnt-1)/n +1;
			if(Col % 2 == 0)//如果是双数
				Row = n - cnt%n +1;
			else//如果是单数
				Row = cnt%n;
			if(Row == 0) Row = n;
			cout << Col << ' ' << Row;
		}
		pq.pop();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}