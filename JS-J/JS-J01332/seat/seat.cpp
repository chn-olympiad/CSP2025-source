#include <bits/stdc++.h>
using namespace std;
int n,m,c;
int a[200],s[15][15],k;
bool b=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    c=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++)
            if(a[i]<a[j]) swap(a[i],a[j]);
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                    //cout<<j<<" "<<i<<endl;
                k++;
                s[j][i]=a[k];
                if(a[k]==c){
                    b=1;
                    cout<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                    //cout<<j<<" "<<i<<endl;
                k++;
                s[j][i]=a[k];
                if(a[k]==c){
                   b=1;
                   cout<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
        if(b) break;
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }*/
	return 0;
}
