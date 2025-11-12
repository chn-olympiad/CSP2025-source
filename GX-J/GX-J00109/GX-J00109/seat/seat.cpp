#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int k[n*m];
cin>>k[0];int l=k[0];
for(int i=1;i<n*m;i++){
    cin>>k[i];

}
for(int i=0;i<n*m;i++){
    for(int t=i+1;t<n*m;t++){
        if(k[i]<k[t]){
            swap(k[i],k[t]);
        }
    }
    if(k[i]==l){
            //cout<<i<<" ";
            //i++;
        cout<<i/m+1<<" ";//i++;
    if((i/m+1)%2==0){
        cout<<m-i%m;
    }else{
        if(i%m==0){
        cout<<"1";return 0;
    }
    cout<<i%m;

    }
    return 0;
    }
}
    return 0;
}
