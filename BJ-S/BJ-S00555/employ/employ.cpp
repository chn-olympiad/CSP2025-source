#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    int a[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            s++;
        }else{
            cout<<a[i]<<" "<<s<<endl;
            s=1;
        }
    }
  
    return 0;
}

