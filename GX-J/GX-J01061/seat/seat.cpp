#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m,a[110],b,c=1,r=1;
    cin>>n>>m;
    cin>>b;
    a[0]=b;
    for(int i=1;i<n*m-1;i++){
        cin>>a[i];
    }
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
            cout<<a[i]<<endl;
        if(a[i]==b){
            cout<<c<<" "<<r;
            break;
        }
        if(c%2==1)r++;
        else{
            r--;
            if(r<1){
                c++;
                r++;
            }
        }
        if(r>n){
            c++;
            r--;
        }

    }
    return 0;
}
