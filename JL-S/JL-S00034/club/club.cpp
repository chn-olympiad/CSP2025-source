#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t = fscanf(stdin, "%d");;
    for(int bb=0; bb<t; bb++)
    {
        int n = fscanf(stdin, "%d");
        vector<int> lst;
        int a, b, c;
        printf("lol");
        for(int m=0; m<n; m++)
        {
            fscanf(stdin, "%d %d %d", a, b, c);
            lst.push_back(a);
            lst.push_back(b);
            lst.push_back(c);
        };
// after reading, we need a fangan to set
        vector<int> fangan;
        for(int i=0; i<n; i++)
        {
            fangan.push_back(0);
        };
calc:
//check

//calc man yi du
        int res=0;
        int tmp=0;
        int q=0,r=0,s=0;
        for (int p=0; p<n; p++)
        {
            tmp = tmp + lst[p*3+fangan[p]-1];
            if(fangan[p]==0)q++;
            if(fangan[p]==1)r++;
            if(fangan[p]==2)s++;
        }
        int uu = n/2;
        if(q<=uu&&r<=uu&&s<=uu)
        {
            res = tmp>res?tmp:res;
        }



        int j=1;
        fangan[fangan.size()-j]++;
        while(fangan.size()-j>2)
        {
            fangan[fangan.size()-j]=0;
            fangan[fangan.size()-j-1]++;
            j++;
            if (j==fangan.size())
            {
                goto final;
            };
        };
        goto calc;

final:

        fprintf(stdout, "%d", res);

    };
    return 0;
}
