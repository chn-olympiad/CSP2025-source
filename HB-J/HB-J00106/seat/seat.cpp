#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[105];
bool flag[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k,s = n * m,a;
	for(int i = 1; i < s; i++){
		cin>>p[i];
		k = p[1];
	}
	sort(p + 1,p + s + 1,cmp);
	for(int i = 1; i <= s; i++){
		if(p[i] == k){
			flag[i] = 1;
			a = i;
		}
	}
	if(k == 1){
		cout<<m<<" "<<n;
		return 0;
	}
	if(n == 1){
		if(m == 1){
			cout<<1<<" "<<1;
			return 0;
		}
		else{
			cout<<a<<" "<<1;
			return 0;
		}
	}
	if(m == 1){
		cout<<1<<" "<<a;
		return 0;
	}
	if(n == 2){
		if(a == 1){
			cout<<1<<" "<<1;
			return 0;
		}
		if(a == 2){
			cout<<1<<" "<<2;
			return 0;
		}
		if(a == 3){
			cout<<2<<" "<<2;
			return 0;
		}
		if(a == 4){
			cout<<2<<" "<<1;
			return 0;
		}
		if(a == 5){
			cout<<3<<" "<<1;
			return 0;
		}
		if(a == 6){
			cout<<3<<" "<<2;
			return 0;
		}
		if(a == 7){
			cout<<4<<" "<<2;
			return 0;
		}
		if(a == 8){
			cout<<4<<" "<<1;
			return 0;
		}
		if(a == 9){
			cout<<5<<" "<<1;
			return 0;
		}
		if(a == 10){
			cout<<5<<" "<<2;
			return 0;
		}
		
		if(a == 11){
			cout<<6<<" "<<2;
			return 0;
		}
		if(a == 12){
			cout<<6<<" "<<1;
			return 0;
		}
		if(a == 13){
			cout<<7<<" "<<1;
			return 0;
		}
		if(a == 14){
			cout<<7<<" "<<2;
			return 0;
		}
		if(a == 15){
			cout<<8<<" "<<2;
			return 0;
		}
		if(a == 16){
			cout<<8<<" "<<1;
			return 0;
		}
		if(a == 17){
			cout<<9<<" "<<1;
			return 0;
		}
		if(a == 18){
			cout<<9<<" "<<2;
			return 0;
		}
		if(a == 19){
			cout<<10<<" "<<2;
			return 0;
		}
		if(a == 20){
			cout<<10<<" "<<1;
			return 0;
		}
	}
	return 0;
}
