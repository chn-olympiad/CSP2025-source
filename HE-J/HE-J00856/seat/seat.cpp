#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,xiaom;
	int fen[n*m];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	xiaom=fen[1];
	for(int i=1;i<n*m;i++){
		if(fen[i]<fen[i+1]){
			s=fen[i];
			fen[i]=fen[i+1];
			fen[i+1]=s;
		}
	}
	int yu=0;
	for(int i=1;i<=n*m;i++){
		if(fen[i]==xiaom){
			yu=(n*m-i)%m;
			if(yu==0){
				if(n*m-1>m){
					cout<<n<<' '<<m;
				}
				else{
				cout<<(n*m-i)/m<<' '<<m;
			    }
			}
			else{
			if(n*m-1>m){
					cout<<n<<' '<<m;
			}
			else{
			cout<<(n*m-i)/m<<' '<<yu;
		    }
			}
		}
	}
	return 0;
}
