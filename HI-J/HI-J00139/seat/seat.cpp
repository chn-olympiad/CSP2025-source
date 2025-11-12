#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	int a1=0;
	cin>>a1;
	for(int i=1;i<=n*m-1;i++){
		int a2;
		cin>>a2;
		if(a2>a1){
			cnt++;
		}
	}
	cnt++;
	int q=(cnt-1)/n;
	int w=cnt%n;
	if(w==0){
		w=n;
	} 
	if(q%2==0){
		cout<<q+1<<' '<<w;
	}else{
		cout<<q+1<<' '<<n-w+1;
	}
	return 0;
}
