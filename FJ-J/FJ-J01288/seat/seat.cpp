#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> Q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int M,N,To=1,X=0,Y=1;
	cin >> N >> M;
	for(int i=1;i<=M*N;i++){
		int A;
		cin >> A;
		Q.push({A,i});
	}
	while(1){
		X+=To;
		if(X>N){
			Y++;
			X--;
			To=-1;
		}else if(X<1){
			Y++;
			X++;
			To=1;
		}
		int Id=Q.top().second;
		if(Id==1){
			cout << Y << " " << X;
			return 0;
		}
		Q.pop();
	}
	return 0;
} 
