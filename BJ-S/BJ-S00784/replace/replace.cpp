#include<bits/stdc++.h>
using namespace std;
int n,q,minl=5100000;
string q1,q2;
struct group{
    string s1,s2;
    int l;
}x[200100];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n>> q;
    for(int i=0 ; i<n ; i++)
    {
        cin >> x[i].s1 >> x[i].s2;
        x[i].l=x[i].s1.length();
        //cout << x[i].l << endl;
    }
    for(int o=0 ; o<q ; o++)
    {
        int ans=0;
        cin >> q1 >> q2;
        for(int i=0 ; i<n ; i++)
        {
            //cout << " "<< i << endl;
          //  cout << q1.length() << endl;
            if(x[i].l > q1.length())  continue;
            for(int j=0 ; j+x[i].l-1 < q1.length() ; j++)
            {
               // cout <<1 << endl;
               //cout << j << endl;
                bool g=true;
                for(int k=0 ; k<j ; k++)
                {
                    if(q1[k] != q2[k])
                    {
                    //    cout << 22 << endl;
                        g=false;
                        break;
                    }
                }
                if(!g) continue;
                for(int k=j+x[i].l ; k<q1.length() ; k++)
                {
                    if(q1[k] != q2[k])
                    {
                     //   cout << 33 << endl;
                        g=false;
                        break;

                    }
                }
                if(!g) continue;
                for(int k=j,k2=0; k<j+x[i].l ; k2++,k++)
                {
                    //cout << q1[k] << endl;
                    //cout << x[i].s1[k2] << endl;
                    if(q1[k] != x[i].s1[k2] || q2[k] != x[i].s2[k2])
                    {
                    //    cout << 44 << endl;
                        g=false;
                        break;
                    }

                }
                if(g)
                {
                    ans++;

                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
