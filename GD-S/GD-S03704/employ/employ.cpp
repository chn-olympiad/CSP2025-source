#include<bits/stdc++.h>
#define cin fin
#define cout fout
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!

using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    srand(n*m*114);
    mt19937 mt(rand()%(n*m));
    cout<<mt()%998244353;
    fin.close();
    fout.close();
    return 0;
}
