#include<bits/stdc++.h>
using namespace std;
int n,m,me,l;
int a[1005];
int b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    me=a[1];
    sort(a+1,a+1+(n*m));
    for(int q=1;q<=m;q++){
            if(q%2!=0){
                for(int w=1;w<=n;w++){
                    b[q][w]=a[l];
                    if(a[l]==me){
                        cout<<q<<" "<<w<<endl;
                    }
                    l-=1;
                }
            }
            else{
                for(int w=n;w>=1;w--){
                    b[q][w]=a[l];
                    if(a[l]==me){
                        cout<<q<<" "<<w<<endl;
                    }
                    l-=1;
                }
            }
    }
    return 0;
}
