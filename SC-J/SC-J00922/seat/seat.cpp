#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int ans=n*m;
    int a[ans+1];
    for(int i=1;i<=ans;i++){
        cin>>a[i];
    }
    int n1=1;
    int n2=0;
    int cnt=1;
    for(int i=2;i<=ans;i++){
        if(a[1]<a[i]) cnt+=1;
    }
    if(cnt<=n) {
        cout<<n1<<" "<<(n2+cnt)<<endl;

    }
    else{
        if(cnt%n==0) n1=(cnt/n);
        if(cnt%n!=0) n1=(cnt/n)+1;
        if(n1%2!=0){
            if(cnt%n==0){
                n2=n;
                cout<<n1<<" "<<n2<<endl;
            }
            if(cnt%n!=0){
                n2=cnt%n;
                cout<<n1<<" "<<n2<<endl;
            }
        }
        if(n1%2==0){
            if(cnt%n==0){
                n2=1;
                cout<<n1<<" "<<n2<<endl;
            }
            if(cnt%n!=0){
                n2=n+1-(cnt%n);
                cout<<n1<<" "<<n2<<endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

//座位
 