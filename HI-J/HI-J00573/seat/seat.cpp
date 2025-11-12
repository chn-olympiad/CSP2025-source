#include<bits/stdc++.h>
using namespace std;
bool cnt(int x,int y){
	return x>y;
}
int main(){
	int n,m,k,hang=0,lir=0;
	int cnp=0;
	cin>>n>>m;
	int s[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	k=s[1];
	sort(s+1,s+n*m+1,cnt);
	for(int i=1;i<=n*m;i++){
		if(s[i]==k){
			break;
		}
		cnp++;
	}
	hang=cnp/n+1;
	if(hang%2==0){
		lir=n-cnp%n;
	}else{
		lir=cnp%n+1;
	}
	cout<<hang<<' '<<lir;
	return 0;
} 
