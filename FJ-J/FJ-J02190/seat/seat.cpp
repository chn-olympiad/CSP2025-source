#include<bits/stdc++.h>
using namespace std;
int n , m , g[15][15] , grade[150];
void my_sort(int nm){
	for(int i = 1 ; i <= nm ; i++){
		for(int j = 1 ; j < nm ; j++){
			if(grade[j] < grade[j+1])
				swap(grade[j] , grade[j+1]);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int nm = n * m;
	for(int i = 1 ; i <= nm ; i++){
		cin >> grade[i];
	}
	int p = grade[1] , pp;
	my_sort(nm);
	for(int i = 1 ; i <= nm ; i++){
		if(grade[i] == p){
			pp = i;
			break;
		}
	}
	int px , pyy = pp % n , py;
	if(pyy){
		px = pp/n + 1;
	}
	else{
		px = pp/n;
	}
	if(px % 2){
		if(pyy == 0){
			py = n;
		}
		else py = pyy;
	}
	else{
		py = n - pyy + 1;
	}
	cout << px << " " << py;
	return 0;
}
