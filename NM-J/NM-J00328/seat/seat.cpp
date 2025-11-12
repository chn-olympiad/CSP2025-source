#include<iostream>
#include<cstring>
using namespace std;

int n,m;
int key;

bool score[101];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    memset(score,0,sizeof(score));
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        if(i==1) key=x;
        score[x]=true;
    }

    int x=1,y=1;
    for(int i=100;i>=1;i--){
        if(!score[i]) continue;

        if(i==key){
            printf("%d %d\n",x,y);
            return 0;
        }

        if(x%2==0){
            if(y==1) x++;
            else y--;
        }
        else{
            if(y==n) x++;
            else y++;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
