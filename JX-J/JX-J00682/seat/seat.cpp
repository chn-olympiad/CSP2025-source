#include<bits/stdc++.h>
using namespace std;

const int N=10*10+10;
int seats[20][20];
int score[N];
int Rscr;

bool cmp(int a,int b){
    if(a>=b) return true;
    return false;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        cin>>score[i];
    }
    Rscr=score[1];

    sort(score+1,score+n*m+1,cmp);

    for(int i=1;;i++){
        if(score[i]==Rscr){
            Rscr=i;
            break;
        }
    }

    int x;
    if(Rscr%n != 0) x=Rscr/n+1;
    else x=Rscr/n;

    int y;
    if(x%2==1){
        y=Rscr%n;
        if(y==0){
            y=n;
        }
    }
    else{
        y=Rscr%n;
        if(y==0){
            y=n;
        }
        y=n-y+1;
    }

    cout<<x<<" "<<y;
    return 0;
}
