#include<bits/stdc++.h>
using namespace std;
int main(){
     freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    srand(time(0));
    int n;
    cin>>n;
    int a[n];
    vector<int> cache;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<rand()%n;
}
