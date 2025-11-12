#include<bits/stdc++.h>
using namespace std;
int a, b, n[1000], c, d;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for(int i=1;i<=a*b;i++){
		cin >> n[i];
	}
	c=n[1];
	sort(n, n+a*b);
	for(int i=a*b;i>=1;i--){
		if(n[i]==c){
			d=a*b-i;
			break;
		}
	}
	if(d%b==0){
		cout << d/b << " ";
		if((d/b)%2==0){
			cout << 1;
		}else{
			cout << b;
		}
		return 0;		
	}else{
		cout << d/b+1 << " ";
		if((d/b+1)%2==0){
			cout << b-d%b+1;
		}else{
			cout << d%b;	
		}
		return 0;
	}
}
