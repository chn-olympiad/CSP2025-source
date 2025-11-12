#include<iostream>
using namespace std;
int a[10010];
int b[10010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    int sum=0,s=0;;
    for(int i=0;i<10000;i++){
        if(b[i]>=1){
            sum+=b[i]-1;
            if(b[i]==1){
                s++;
            }
        }
    }
    if(sum==0){
        cout<<s*2-1;
    }
    else{
        cout<<sum*3+s;
    }
    return 0;
}
