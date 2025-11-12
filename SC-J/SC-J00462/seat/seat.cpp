#include<fstream>
#include<algorithm>

std::fstream input("seat.in");
std::fstream output("seat.out");

int main(){
    int n, m;
    input>>n>>m;
    int seats[n*m];
    for(int i = 0; i < n*m; i++)
        input>>seats[i];
    int R = seats[0], seatnum;
    std::sort(seats, seats+(n*m));
    for(int i = 0; i < n*m; i++){
        if(seats[i] == R)
            seatnum = i;
    };
    output<<(seatnum/n+1)<<(seatnum%n);
};