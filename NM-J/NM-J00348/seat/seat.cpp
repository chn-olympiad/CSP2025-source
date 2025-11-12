#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a=n*m;
    int b[a+7];
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }
    int c=0,d=b[1];
    for(int i=1;i<=a;i++){
        for(int j=i+1;j<=a;j++){
            if(b[i]<b[j]){
                swap(b[i],b[j]);
            }
        }
    }
    for(int i=1;i<=a;i++){
        if(b[i]==d){
            c=i;
            break;
        }
    }
    if(c%n==0){
        cout<<c/n<<" "<<n;
        return 0;
    }else{
        cout<<c/n+1<<" "<<c-c/n*n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
