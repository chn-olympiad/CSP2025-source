#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int num;
int a[500];
int x,y,pos,dir;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    num=a[1];
    sort(a+1,a+n*m+1,cmp);
    dir=1;//1:down 2:right 3:up 4:right
    x=1;
    y=1;
    pos=1;
    while(a[pos]!=num){
        //cout<<x<<" "<<y<<endl;
        if(dir==1){
            x++;
            if(x==n){
                dir++;
            }
        }else if(dir==2||dir==4){
            y++;
            dir++;
        }else{
            x--;
            if(x==1){
                dir++;
            }
        }
        if(dir==5) dir=1;
        pos++;
    }
    cout<<y<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
