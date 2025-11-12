/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num = n * m;
	int ni = 0; 
	if(num == 1) {
		cout<<1<<" "<<1;
		return 0;
	}
	vector<int> a(num);
	cin>>a[0];
	for(int i=1; i<num; i++){
		cin>>a[i];
		if(a[i]>a[0])ni++;
	}
	if((ni/m)%2==0){
		cout<<ni/m+1<<" "<<ni%m+1<<endl;
	}else{
		cout<<ni/m+1<<" "<<m-(ni%m)<<endl;
	}
	return 0;
} 
