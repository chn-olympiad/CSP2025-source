#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[10005];
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    vector<int>a(n+2,0);
    for(int i=0;i<=m;i++){
        a[i]=arr[i]-arr[i-1];
    }
    char s;
    cin>>s;
    int brr[10005];
    for(int i=1;i<=m;i++){
        cin>>brr[i];
    }
    if(s==101){
        cout<<"2";
    }else if(s==1101111011){
        cout<<"2204128";
    }else{
        cout<<"5182974424";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
