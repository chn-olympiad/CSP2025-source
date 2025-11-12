#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r,a[1005],p,x;
    queue<int> b;
    cin>>c>>r;
    for(int i=1;i<=c*r;i++){
        cin>>a[i];
        p=a[1];
    }
    sort(a+1,a+1+c*r);
    for(int i=c*r;i>=1;i--){
        b.push(a[i]);
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(b.front()==p){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
            b.pop();
        }
        i++;
        for(int j=c;j>=1;j--){
            if(b.front()==p){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
            b.pop();
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
