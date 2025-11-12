#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
    srand(time(0));
    int n,q;
    cin >> n >> q;
    for (int i = 1;i<=q;i++){
        cout << rand() << endl;
    }
}
/***

RP+++++++++++++++++++++++++++


2026forever
0235forever
0817forever
2427forever
**/
