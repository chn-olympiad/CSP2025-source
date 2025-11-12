#include<bits/stdc++.h>
using namespace std;
int main()
{
    system("g++ -o a a.cpp -O2 -fsanitize=undefined,address -std=c++14 -Wall");
    system("g++ -o b b.cpp -O2 -fsanitize=undefined,address -std=c++14 -Wall");
    system("g++ -o d d.cpp -O2 -fsanitize=undefined,address -std=c++14 -Wall");
    int tot=0;
    while(1)
    {
        tot++;
        cout<<tot<<"\n";
        system("./d >a.in");
        system("./a <a.in >a.out");
        system("./b <a.in >a.out");
    }
}