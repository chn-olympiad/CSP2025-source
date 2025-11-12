#include<bits/stdc++.h>
using namespace std;

int n, m, a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x = n*m;
	for(int i = 1;i <= x;i++){
		cin>>a[i];
	}
	
	int R = a[1], g;
	sort(a+1,a+x+1);
	int j = 1;
	for(int i = x;i >= 1;i--){
		if(a[i] == R){
			g = j;
			break;
		}
		j++;
	}
	
	if(g % m == 0){
		cout<<g/m<<" "<<n;
	}else{
		cout<<g/m+1<<" ";
		if((g/m+1) % 2 == 0){
			cout<<n;
		}else{
			cout<<1;
		}
	}
	return 0;
} 