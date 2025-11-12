#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
string n;
string a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> n;
    for(int i=0;i<n.size()+1;i++){
        if(n[i]>='0'&&n[i]<='9'){a[i]=n[i];}

    }
    sort(a,a+n.size()+1);
    for(int j=n.size()+1;j>0;j--){
        cout<<a[j];

    }
    return 0;

}
