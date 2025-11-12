#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char a[1200000],b;
int w[1200000],sum = 1;
int main(){
	cin >> (a+1);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	for(int i = 1;i <= strlen(a+1);i++){
		
		if(a[i]>= 48 && a[i] <= 57){
			
			w[sum] = int(a[i]) - 48;
			
			sum++;
		}
	}
	sort(w,w+sum);
	for(int i = sum-1;i>= 1;i--){
		cout << w[i];
	}	
	
	
	
	
	
	
	return 0;
	
} 
