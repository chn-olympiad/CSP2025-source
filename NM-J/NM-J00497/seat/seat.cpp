#include<bits/stdc++.h>
using namespace std;
int m,n,a,b[1000]={0},c,d[1000]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>c;
		if(i==1){
			a=c;
		}
		b[c]++;
	}
	
	int k = 1;
	for(int i = 100;i >= 0;i--){
		for(int j = 1;j <= b[i];j++){
			d[k]=i;
			k++;
		}
	}
	for(int i=1;i<=m*n;i++){
		//d[i]
		//(i-1)/n+1
		//((i-1)%n)+1
		if(d[i]==a){
			//cout<<d[i]<<endl;
			if(((i-1)/n+1)%2==1){
				cout<<(i-1)/n+1<<' '<<((i-1)%n)+1;
			}else{
				
				cout<<(i-1)/n+1<<" "<<n-((i-1)%n);
			}
		}
		
	}
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
*/
