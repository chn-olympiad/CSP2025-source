#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[100],c=1,r=1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[0]<a[i]){
            if(c%2==0){
                if(r==1)
                    c++;
                else
                    r--;
            }
            else{
                if(r==n)
                    c++;
                else
                    r++;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
