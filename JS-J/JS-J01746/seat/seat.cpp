#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int b,int c){
    return b>c;


}
int main(){
    ifstream in("seat.in");
    ofstream out("seat.out");
    in>>n>>m;
    for(int i=1;i<=n*m;i++){
        in>>a[i];
    }
    int b=a[1];
    int c;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            c=i;
            break;
        }
    }
    int l;
    int k=(c+n-1)/n;//lie

    if(k%2==0){
        l=n+1-(c%n);
    }
    else{
        l=c%n;
        if(l==0){
            l=n;
        }
    }
    out<<k<<" "<<l;
    return 0;
}
