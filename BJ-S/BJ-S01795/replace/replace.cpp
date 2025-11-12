#include<bits/stdc++.h>
using namespace std;
struct c
{
    string a, b;
}s[200005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
   int t, n;
   cin >> t >> n;
   for (int i=1;i<=t;i++)
   {
       string j, k;
       cin >> j >> k;
       s[i].a=j;
       s[i].b=k;

   }
   //cout << s[1].a;
   for (int twty=1;twty<=n;twty++)
   {
       int fas=0;
       string j, k;
       cin >> j >> k;
       for (int i=1;i<=t;i++)
       {
           //cout << i << '\n';
           string h="";
           int l=s[i].a.size();
            if (l>j.size())
                continue;
           for (int twi=0;twi<=j.size()-l;twi++)
           {
               h="";
               //cout << l << '\n';
               //cout << tw << '\n';
               for (int tw2=twi;tw2<=twi+l-1;tw2++)
               {
                   h+=j[tw2];
                   //cout << tw2 << "\n";
               }
               //cout << h << "\n";
               if (h==s[i].a)
               {
                   //cout << 1 << '\n';
                   string s1="";
                   for (int ii=0;ii<twi;ii++)
                    s1+=j[ii];
                    //cout << s1 << '\n';
                   s1+=s[i].b;
                    //cout << s1 << '\n';
                   for (int ii=twi+l;ii<j.size();ii++)
                    s1+=j[ii];
                    //cout << s1 << " ceshi\n";
                   if (s1==k)
                    fas++;
               }
           }
       }
       cout << fas << '\n';
   }
   return 0;
}

