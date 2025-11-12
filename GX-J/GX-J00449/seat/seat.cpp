#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int a,b;
    cin >> a >> b;
    int c[a+1][b+1];
    int px[a*b+1];

    for(int i=1;i<=a*b;i++)
    {
        cin >> px[i];
    }

    int r = px[1];

    for(int i=1;i<=a*b;i++)
    {
        for(int j=1;j<=a*b;j++)
    {
        if(px[j]<px[j+1])
        {
            swap(px[j],px[j+1]);
        }
    }
    }

        int q;

    for(int i=1;i<=a*b;i++)
    {
        //cout <<px[i] << " ";
        if(r==px[i])
    {
        q = i;
    }
    }

//cout << endl << q << endl;

    int ls=0,hs=0;
    hs = abs(q-2*a);
    ls = q/a;
    if(q%a==1)
    {
        ls+=1;
    }



    cout << ls <<" " << hs;


    return 0;
}
