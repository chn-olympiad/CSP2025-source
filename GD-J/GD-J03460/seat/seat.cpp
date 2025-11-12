#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(seat1,"d");
	fclose(seat1,"s");
	int n,m,x,cnt=0;
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		int c;
		cin>>c;
		if(x<c){
			cnt++;
		}
	}cout<<cnt/n+1<<" ";
	if((cnt/n+1)%2==1){
		cout<<cnt%n+1;
	}else{
		cout<<n-cnt%n;
	}
	return 0;
}
