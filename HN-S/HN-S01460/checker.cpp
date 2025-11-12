#include<bits/stdc++.h>
using namespace std;
int cnt;
void Work(){
    system("./gen < seed.txt > data.in");
    system("./std < data.in > std.out");
    if(system("./test < data.in > test.out")){
        printf("RE on #%d\n",cnt);
        exit(0);
    }
    if(system("diff test.out std.out -Bb")){
        printf("WA on #%d\n",cnt);
        exit(0);
    }
    printf("AC on #%d\n",cnt);
    cnt++;
}
int main(){
    system("g++ test.cpp -o test -fsanitize=address,undefined -g");
    system("g++ std.cpp -o std");
    system("g++ gen.cpp -o gen");
    while(1){
        Work();
    }
}