#include <bits/stdc++.h>
using namespace std;

int n, m;
int sea[2];
int mark, ind = 1, mar;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    int num = n*m;
    for(int i=1; i<=num; i++){
        if(i == 1) cin >> mark;
        else{
            cin >> mar;
            if(mar > mark) ind++;
        }
    }

    sea[0] = ind / n;
    sea[1] = ind % m;
    
    if(sea[1]) sea[0] ++;
    
    if(!(sea[0] % 2) && sea[1]){
    	sea[1] = n - sea[1] + 1;
	}
	
	if(sea[1] == 0){
		if(!(sea[0] % 2)){
			sea[1] = 1;
		}
		else sea[1] = n;
	} 
	
    cout << sea[0] << " " << sea[1];

    return 0;
}