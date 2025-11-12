#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,ans= 0;
	int a[1001];
	cin >> s;
	while(s =! 0){
		s = s/10;
		ans++;
	}
	for(int i = 0;i<ans;i++){
		a[i] = s%10;
		s/=10;
	}
	for(int j = 0;j<ans;j++){
		for(int h = 0;j<h;j++){
			if(a[h]>a[h+1]){
				s = a[h+1];
				a[h+1] = a[h];
				a[h] = s;
			}
		}
	}
	while(ans =! -1){
		ans--;
		cout << a[ans-1];
	}
	return 0;
} 
