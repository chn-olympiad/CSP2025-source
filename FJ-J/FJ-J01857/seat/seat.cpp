#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin >>a[i];
		if(a[i]>a[1])	cnt++;
	}
	cnt++;
	int q2=cnt/(2*n);
	int q3=cnt%(2*n);
	if(q3<=n){
		cout <<q2*2+1<<" "<<q3;
	}else{
		cout <<q2*2+2<<" "<<n+1-(q3-n);
	}
	return 0;
} 
