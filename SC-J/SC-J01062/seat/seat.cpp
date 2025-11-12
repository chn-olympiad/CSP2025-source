#include<bits/stdc++.h>
using namespace std;
int cj[405];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mc=0;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
		if(cj[i]>=cj[1])mc++;
	}
	int ans_1,ans_2;
	if(mc%n==0){
		ans_1=mc/n;
	}else{
		ans_1=mc/n+1;
	}
	if(ans_1%2==1){
		ans_2=mc-ans_1*n+n;
	}else{
		ans_2=1-mc+ans_1*n;
	}
	cout<<ans_1<<' '<<ans_2;
	return 0;
}