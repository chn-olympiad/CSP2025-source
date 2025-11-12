#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    srand(time(0));
    cout<<rand()%1000000000;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

