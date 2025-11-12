#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat","r",stdin);
    freopen("seat","w",stdout);
    int m,n,c,r;
    cin>>m>>n;
    int s[100000],a[n][m],d[100000];
    for(int i=1;i<=m*n;i++){
        cin>>s[i];
        d[i]=s[i];
    }
    int w=1,q;
    for(int i=1;i<=n*m-1;i++){
        for(int j=1;j<=n*m;j++){
            if(d[j]<d[j+1]){
                int b=d[j+1];
                d[j+1]=d[j];
                d[j]=b;
            }
        }
    }

    for(int i=1;i<=n;i++){
        q=m;
        for(int j=1;j<=m;j++){
            if(i%2==1){
                a[i][j]=d[w];
                w++;
            }else{
                a[i][q]=d[w];
                w++;
                q--;
            }
            if(a[i][j]==s[1]){
                c=i;
                r=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==s[1]){
                c=i;
                r=j;
            }
        }
    }
    cout<<c<<" "<<r;



    return 0;
}
