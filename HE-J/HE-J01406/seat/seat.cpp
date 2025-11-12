#include<iostream>//nĞĞmÁĞ 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int ren=n*m;
	int fen[ren],R=0;
	for(int i=0;i<n*m;i++){
		cin>>fen[i];
	}
	int c=0,r=0;
	R=fen[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<i;j++){
			if(fen[i]>fen[j]){
				int t=fen[i];
				fen[i]=fen[j];
				fen[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(fen[i]==R){
			if(i>n){
				c=i/n;
				r=i%n+1;
			}else{
				r=i+1;
			} 
		}
	}
	if(c==0){
		c++;
	}
	cout<<c<<" "<<r;
	return 0;
}
