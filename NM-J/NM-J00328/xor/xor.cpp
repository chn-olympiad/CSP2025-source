#include<iostream>
#include<cstring>
using namespace std;

const int N=5010;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
