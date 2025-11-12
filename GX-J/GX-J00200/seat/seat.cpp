#include <bits/stdc++.h>
using namespace std;

int n,m,a[11][11],s[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                a[j][i]=x;
                x++;
            }
        }else{
            for(int j=1;j<=m;j++){
                a[j][i]=x;
                x++;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
        scanf("%d",&s[i]);
    int aa=s[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(s[i]>s[j]){
                int S=s[i];
                s[i]=s[j];
                s[j]=S;
            }
        }
    }
    int l=1;
    for(int i=1;i<=n*m;i++){
        if(s[i]!=aa){
            l++;
        }else{
            l++;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[j][i]==l){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
}
