#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,shu[100]={0},pai=1;
	cin>>x>>y;
	int ben;
	cin>>ben;
	for(int i=1;i<x*y;i++){
		cin>>shu[i];
		if(ben<shu[i]){
			pai++;
		}
	}
	if(pai%(x*2)>=1&&pai%(x*2)<=x){
		cout<<(pai+x-1)/x<<' '<<(pai-1)%x+1;
	}else{
		cout<<(pai+x-1)/x<<' '<<x-((pai+1)%x);
	}
	return 0;
}
