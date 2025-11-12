#include <bits/stdc++.h>
using namespace std;
#define zd long long

int main()
{
    int stickLen[6000];
    ifstream read_f;
    read_f.open("polygon1.in");
    int n;
    read_f>>n;
    for (int i=0;i<n;i++){
        read_f>>stickLen[i];
    }
    ofstream save_f;
    save_f.open("polygon.out");
    return 0;
}
