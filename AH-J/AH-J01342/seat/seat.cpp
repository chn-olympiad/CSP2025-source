#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[101]={};
    cin >> n >>m;
    for (int i=0;i<n*m;i++){
        cin >>a[i];
    }
    int x=a[1];
    int y=0;
	sort(a,a+101+1);
    for (int i=0;i<101;i++){
        if (a[i]==x){
            y=i;
        }
    }
    if (y==1) cout << "1 1";
    if (y==2) cout << "1 2";
    if (y==3) cout << "1 3";

    return 0;
}
