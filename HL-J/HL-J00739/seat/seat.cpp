#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long N,M;
	priority_queue<int> a;
	cin>>N>>M;
	long long zong=N*M;
//    R grade
	long long qiu;
	cin>>qiu;
	a.push(qiu);
	for(long long p=1;p<zong;p++){
		long long lin;
		cin>>lin;
		a.push(lin);
	}
	long long l=1;
	while(a.top()!=qiu){
		l++;
		a.pop();
	}
	long long n1=0,m1=0;
	if(l%N!=0){
		m1=l/N+1;
	}else{
		m1=l/N;
	}
	if(m1%2==0){
		if(l%N==0){
			n1=N;
		}else{
			n1=N-l%N+1;
		}
	}else{
		if(l%N==0){
			n1=N;
		}else{
			n1=l%N;
		}

	}
	cout<<m1<<" "<<n1;
	return 0;
}
