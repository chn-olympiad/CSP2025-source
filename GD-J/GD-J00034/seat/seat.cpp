#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n,m;
	cin>>n>>m;
	
	int num = n*m;
	
	int a[105];
	int a1 = 0;
	cin>>a1;
	for(int i = 1;i < num;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+num+1,cmp);
	
	int id = 1;
	for(id;id < num;id++){
		if(a1 > a[id]){
			break;
		}
	}
	
	int x = ceil(id*1.0/m);
	
	int y;
	if(x%2 == 0) y = n+1 - (id%n);
	else y = id%n;
	
	if(y == 0) y = n;
	
	cout<<x<<" "<<y<<endl;
	
	return 0;
} 
