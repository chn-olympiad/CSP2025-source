#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],s[150];
int xiar;
bool jixu=1;
bool cmp(int a,int b){
    return a>b;
}
//down right up
void ddfs(int i,int j,int cs){
    /*cout<<cs<<" "<<i<<"   "<<j<<"   "<<a[i][j]<<"   "<<s[cs];
    cout<<endl;*/
    a[i][j]=s[cs];
    if(a[i][j]==xiar){
        printf("%d %d",j,i);
        jixu=0;
    }
    if(i>=1&&i<n&&a[i+1][j]==0){
        i++;
    }else if(i<=n&&i>1&&a[i-1][j]==0){
        i--;
    }else{
        j++;
    }
    cs++;
    if(jixu)
        ddfs(i,j,cs);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    //xian lie hou hang
    for(int i=1;i<=n*m;i++){
        scanf("%d",&s[i]);
        if(i==1){
            xiar=s[i];
        }
    }
    sort(s+1,s+n*m+1,cmp);
    ddfs(1,1,1);
    return 0;
}

