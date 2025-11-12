#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int seats[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    //Open IO Files
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int all=n*m,score=0;
    for(int i=1;i<=all;i++)scanf("%d",&seats[i]);
    score=seats[1];
    sort(seats+1,seats+all+1,cmp);
    int x=0,y=1,cx=0,cy=0,f=1;
    for(int i=1;i<=all;i++){
        x+=f;
        if((x==n+1)||(x==0)){
            y++;
            if(f==-1)x=1;
            else x=n;
            f*=-1;
        }
        if(seats[i]==score){
            cx=x,cy=y;
            break;
        }
    }
    printf("%d %d\n",cy,cx);
    //Close IO Files
    fclose(stdin);
    fclose(stdout);
    return 0;
}