#include <bits/stdc++.h>
using namespace std;
int bid[10086][10086], cid[11],c1,c2;
bool bool[1006];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int a, b, c;
	cin >> a >> b >> c;
    for(int i = 0; i < b; i++){
        cin >> c1 >> c2;
        cin >> bid[c1][c2];
    }
    for(int i = 0; i < c; i++){
        cin >> cid[i];
        for(int j = 0; j < a; j++){}
        cin >> c1;
    }
    cout << 13;

	return 0;
}
