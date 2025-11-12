#include<studio>
using namespace,std;
int main(){
    freopen("polygon.in","r",std);
    freopen("polygon.out","w",std);
    int i,n;
    cin >> i,n;
    if(n >= i >= 1){
       cout << i % 998 << endl << i % 244 << endl << i % 353 << endl;
    }
    return 0;
}
