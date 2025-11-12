#include <bits/stdc++.h>
using namespace std;
#define zd long long

int MaxNum(int a,int b){
    return a>b;
}


int main()
{
    ifstream read_f;
    read_f.open("seat.in");
    int lie,hang;
    read_f>>hang>>lie;
    int weizhi1[hang*lie];
    for (int i=0;i<hang*lie;i++){
        read_f>>weizhi1[i];
    }
    int R_seat = weizhi1[0];
    sort(weizhi1,weizhi1+hang*lie,MaxNum);
    zd hangctn=1,liectn=1,ctn=0;
    while (true){
        if (weizhi1[ctn]==R_seat){
            break;
        }
        else{
            if (hangctn%2!=0){

                if (liectn>=lie){
                hangctn++;
                liectn=lie;
            }else{
            liectn++;
            }
            }
            else{

                if (liectn<=1){
                hangctn++;
                liectn=1;
            }else{
            liectn--;
            }
        }
        ctn++;
    }}

    ofstream save_f;
    save_f.open("seat.out");
    save_f<<hangctn<<' '<<liectn;
    return 0;
}
