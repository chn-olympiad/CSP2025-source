#include<seat.in>
using namespace std;

int main{
    int n,m,a;
    cin>>n>>m>>a;
    for(int i=1;i<=n*m;i++){
        int b,c=0,d=1;
        cin>>b;
        int num=0;
        if(num > b && d%2 != 0){
            c++;
        }
        else if(c==n || c==1){
            d++;
        }
        else if(num > b && d%2 == 0){
            c--;
        }
        else{
            d++;
        }
    }
    return 0;
}