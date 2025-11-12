#include <bits/stdc++.h>
using namespace std;
//Jhongguo youjv guhua 
//jiaozuo......
//xixiwuzi
//veijuenjie
int sb[11451];
ifstream fin;
ofstream fout;
pair<int,int> zhuanhuan(int seat,int maxc,int maxr)
{
    int column = ceil(seat*1.0/maxr);
    int row = (column%2?((seat%maxr)?(seat%maxr):maxr):(maxr+1-((seat%maxr)?(seat%maxr):maxr)));
    return make_pair(column,row);
}
int main()
{
    fin.open("seat.in");
    fout.open("seat.out");
    int n,m;
    fin >> n >> m;
    for(int i = 1;i <= n*m;i++) fin >> sb[i];
    int tmp = sb[1];
    sort(sb+1,sb+n*m+1,greater<int>());
    for(int i=1;i <= n*m;i++) if(sb[i] == tmp)
    {
        tmp=i;
        break;
    }
    pair<int,int> k = zhuanhuan(tmp,m,n);
    fout << k.first << ' ' << k.second;
    return 0;
}
/*
             o
        OOOOOOOOOOO
    OOOOOOOOOOOOOOOOOOOO
    OO       ·        OO
    OO                OO
    OO  ----   ----   OO
    OO       /        OO
    OO      /_        OO
    OO                OO
    OO     ____       OO
      \______________/
           |    |
      _____|    |_____
     /     \    /     \
     |      \  /      |
     L_______\/_______|
     本人代码写得不好，
     啥都不求，只求能过。
     求求了😢
*/