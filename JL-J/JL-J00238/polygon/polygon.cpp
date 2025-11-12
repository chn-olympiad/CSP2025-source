#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,all=0,a,c=0,zh=0,max1=-1;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin>>a;
        vec.push_back(a);
        c++;
        zh+=a;
        if(a>max1) max1=a;
    }
    for(int i=0;i<(1+c)*c/2;i++){
        if(max1*2<zh) all++;
    }
    cout<<all%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
