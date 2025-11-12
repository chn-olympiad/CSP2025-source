#include<bits/stdc++.h>
using namespace std;

const int XM=1100;
int n,m;
struct P{
    int score;
    int name=0;
    bool operator <(const P & others){
        return score>others.score;
    }
};
P a[1000];


int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
    }
    a[1].name=XM;
    if(n==m&&m==1) {
        cout<<1<<' '<<1;
        return 0;
    }

    sort(a+1,a+n*m+1);
//h -> n
//b -> m

    for(int i=1;i<=n*m;i++){
        if(a[i].name==XM){//find Xiao Ming
            int b=0,h=0;

            if(i%n==0){
                b=i/n;
                if(b%2==0){
                    h=1;
                }
                else{
                    h=n;
                }
            }
            else{

                b=i/n+1;
                if(b%2==0){
                    int len=i-n*(b-1);
                    h=n-len+1;
                }else{
                    h=i-(b-1)*n;
                }

            }

            cout<<b<<' '<<h;
            return 0;
        }

    }
    return 0;
}
