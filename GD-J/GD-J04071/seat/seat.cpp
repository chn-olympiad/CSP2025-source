#include<bits/stdc++.h>
using namespace std;
long long n,p,m,o,k;
long long ch[500];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	
	for(int i = 0;i < n * m;i ++){
		cin >> ch[i];
	}
	
	o = ch[0];
	sort(ch,ch + n * m,cmp);
	
	for(int i = 0;i < n * m;i ++){
		if(ch[i] == o){
			p = i + 1;
			break;
		}
	}
	
	cout << p / n + !(p % n == 0) << " ";
	
	k = p % n;
	if((p / n + 1) % 2 == 0){
		cout << n - k + !(p % n == 0);
	}
	else{
		cout << k;
	}
	return 0;
}
