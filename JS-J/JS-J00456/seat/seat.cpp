#include<bits/stdc++.h>
using namespace std;


int main(){


    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int sum = n*m;

    int me,bigger_than_me=0,now;
    cin>>me;
    for(int i=1;i<sum;i++){
        cin>>now;
        if(now>me){
            bigger_than_me++;
        }

    }
    int my_seat=bigger_than_me+1;

    if(my_seat%n==0){
        if((my_seat/n)%2==0){
            cout<<my_seat/n<<' '<<1;
        }
        else{
            cout<<my_seat/n<<' '<<n;
        }
    }
    else if(my_seat%n!=0){
        if((my_seat/n)%2==0){
            cout<<my_seat/n+1<<' '<<my_seat%n;

        }
        else{
            cout<<my_seat/n+1<<' '<<n+1-my_seat%n;
        }
    }



	return 0;
}
