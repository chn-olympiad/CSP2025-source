#include <bits/stdc++.h>

using namespace std;

int a[101];

bool cmd(int a,int b){
    return a>b;
}


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r=0,x=0,y=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    r = a[0];
    sort(a,a+n*m,cmd);
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            if(i/n%2==0){
                x = i%n;
                y = i/n;
            }else{
                x = n-i%n-1;
                y = i/n;
            }
            break;
        }
    }
    cout<<y+1<<" "<<x+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
