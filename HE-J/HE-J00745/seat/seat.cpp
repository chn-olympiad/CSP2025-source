#include<bits/stdc++.h>
using namespace std;
int main(){
	freeopen("seat.in","w",stdin);
	freeopen("seat.out","r",stdout);
	int m,n,s,fen[105],pai[105]={0},sum=0,hang,lie;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>s;
		fen[i]=s;
		pai[s]=1;
	}for(int i=100;i>=0;i--){
		if(pai[i]==1){
			sum++;
		}if(fen[1]==i){
			break;
		}
	}lie=(sum-1)/n+1;
	if(lie%2==0){
		if(sum%n==0){
			hang=1;
		}else{
			hang=n-sum%n+1;
		}
	}else{
		if(sum%n==0){
			hang=n;
		}else{
			hang=sum%n;
		}
	}cout<<lie<<" "<<hang;
}
