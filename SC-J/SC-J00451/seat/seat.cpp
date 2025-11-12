#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int rn,n,m;
	cin>>n>>m;
	cin>>rn;
	int rank=1;
	for(int i=1;i<m*n;i++){
		int x;
		cin>>x;
		if(x>rn){
			rank++;
		}
	}
	int round,yu;
	yu=rank%(n*2);
	round=(rank-yu)/(2*n);
	if(yu==0){
		cout<<2*round<<" "<<1;
	}else if(yu<=n&&yu>0){
		cout<<2*round+1<<" "<<yu;
	}else{
		cout<<2*round+2<<" "<<2*n-yu+1;
	}
	return 0;
}