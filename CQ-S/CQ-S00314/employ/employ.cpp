#include<bits/stdc++.h>
using namespace std;
mt19937 random_frog(time(nullptr));
int main(){
    ios::sync_with_stdio(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cout<<random_frog()%521;
    return 0;
}