#include<bits/stdc++.h>
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
using namespace std;
int main(){
    int n,m,me,b;
    cin>>n>>m>>me;
    int a[m*n-1];
    a[0] = me;
    for(int i = 1;i<=n*m-1;i++){
        cin>>a[i];
        for(int j = 0;j<i;j++){
            if(a[j]<a[i]){
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }

    for(int i = 0;i<n*m;i++){
        if(a[i] == me)  b = i+1;
    }
    int c = (b/n)+1;s
    if(c%m==0)  cout<<m-((b-(m-1))%m)<<" "<<c<<endl;
    else  cout<<(b-(m-1))%m<<" "<<c<<endl;
    return 0;
}

