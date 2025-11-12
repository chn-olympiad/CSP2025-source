#include<bits/stdc++.h>
using namespace std;
int a[10]; 
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	//ios::sync_with_stdio(false);
	for(int i=0;i<10;i++){
		a[i]=0;
	}while(cin>>c){
		if('0'<=c&&'9'>=c){
			a[c-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
