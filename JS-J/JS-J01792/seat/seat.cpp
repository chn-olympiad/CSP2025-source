#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","w",stdout);
    int mark[114],n,m,r,num;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>mark[i];
    }
    r=mark[1];
    sort(mark,mark+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(mark[i]==r){
            num=m*n-i+1;
            if((num/n+1)%2==1){
                cout<<num/n+1<<" "<<num%n;
            }
            else{
                if(num==n){
                    cout<<num/n<<" "<<n;
                }
                else{
                    cout<<num/n+1<<" "<<n-(num%n)+1;
                }

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
