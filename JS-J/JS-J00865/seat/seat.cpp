#include<bits/stdc++.h>
using namespace std;
ifstream fin("seat.in");
ofstream fout("seat.out");
int a[111];
int b[111];
int main(){
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n*m;i++){
        fin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int q;
    for(int i=1;i<=n*m;i++){
            if(a[i]==p){
                q=i;
            }
    }
    int x=q/n;
    int y=q%n;
    if(y==0){
        y=n;
        x=x-1;
    }
    if(x%2==0){
        fout<<x+1<<" "<<y;
    }
    else{
        fout<<x+1<<" "<<n+1-y;
    }
}
