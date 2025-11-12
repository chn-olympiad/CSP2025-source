#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("seat.in");
	ofstream out("seat.out");
	int cnt=0,n,m,c,r,score;
	in>>n>>m>>score;
	for(int i=1;i<n*m;i++){
		int a;
		in>>a;
		if(a>score){
			cnt++;
		}
	}
	out<<cnt/n+1<<' ';
	if((cnt/n+1)%2) {
		out<<cnt%n+1;
	}
	else{
		out<<n-cnt%n;
	}
	return 0;
}
