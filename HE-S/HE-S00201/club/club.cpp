#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
const int nn = 100005;
int aaa[7][nn][5];

int csz;
int n;
//int xz;

//vector<vector<int>>myd11;
//vector<vector<int>>myd21;
//vector<vector<int>>myd31;
int a1,a2,a3;
/*void findzyj(int ii,int jj)
{
    for(int i=1;i<=jj;i++)
    {
        int js1 = 0,js2 = 0,js3 = 0;
        int maxxx = max(aaa[ii][i][1],aaa[ii][i][2],aaa[ii][i][3]);
        if(maxxx==aaa[ii][i][1])js1++;
        if(maxxx==aaa[ii][i][2])js2++;
        if(maxxx==aaa[ii][i][3])js3++;

    }


}*/

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> csz;
    //myd1.push_back(0);
    //myd2.push_back(0);
    //myd3.push_back(0);

    for(int i = 1;i <= csz;i++)
    {
        cin >> n;
        int x = 0;
        //xz=n/2;
        for(int j = 1;j <= n;j++)
        {
            cin >> a1 >> a2 >> a3;
            x+=max(a1,max(a2,a3));
        }


    }





    return 0;
}
