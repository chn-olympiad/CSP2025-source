#include<bits/stdc++.h>

using namespace std;

int n,m;
int Stucache;
int StuList[200];
int R;
int id;
int need_add;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	//in
	cin >> n >> m;
	cin >> R;
	StuList[R]++;
	
	//list in
	for(int i = 1 ; i < n*m ; i++){
		cin >> Stucache;
		StuList[Stucache]++;
	}
	
	//R id
	for(int i = 100 ; i >= 1 ; i--){
		if(StuList[i]){
			id++;
			if(i == R){
				break;
			}
		}
	}
	
	//out:
	//need add?
	if(id%n == 0){
		need_add = 0;
	}else{
		need_add = 1;
	}
	//r:
	cout << id/n+need_add;
	
	//space:
	cout << " ";
	
	//c:
	if((id/n+need_add)%2 == 0){
		cout << n-id%n+1;
	}else{
		if(id%n == 0){
			cout << n;
		}else{
			cout << id%n;
		}
	}
		
	return 0;
}
