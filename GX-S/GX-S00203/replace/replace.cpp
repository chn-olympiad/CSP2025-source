#include <bits/stdc++.h>
using namespace std;
long long sum=1;
int main(){
    for(int i=1;i<=50;i++){
        sum*=i;
    }
    cout<<sum;
    return 0;
}
