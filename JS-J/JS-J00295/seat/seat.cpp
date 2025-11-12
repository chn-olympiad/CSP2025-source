#include <bits/stdc++.h>
using namespace std;
int ant[1000001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ll;
    cin>>n>>m;
    cin>>ll;
    ant[0]=ll;
    for(int i=1;i<n*m-1;i++){
        cin>>ant[i];
    }
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m;j++){
            if(ant[j]<ant[j+1]){
                int temp=ant[j];
                ant[j]=ant[j+1];
                ant[j+1]=temp;
            }
        }
    }
    int h,f;
    for(int i=0;i<n*m;i++){
        if(ant[i]==ll){
            h=i/n+1;
            f=i%n;
        }
    }
    if(h%2==0) cout<<h<<" "<<n-f<<endl;
    else {
        if(f==0) cout<<h<<" "<<1<<endl;
        else     cout<<h<<" "<<f<<endl;
    }
    return 0;
}
