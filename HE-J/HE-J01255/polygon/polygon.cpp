#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,j,k,l;
    cin >>n;
    cin >>j>>k>>l;
    if(n<=2){
        cout <<0;
    }
    else if(n=3){
        if(j+k>l && l+k>j && j+l>k){
            cout <<1;
        }
        else {
            cout <<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

