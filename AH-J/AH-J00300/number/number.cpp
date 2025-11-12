#include<bits/stdc++.h>
using namespace std;
vector <int> v;
int main(){
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=s.size();i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(s[j]>='0' && s[j]<='9')
            {
                int a=int(s[j])-48;
                v.push_back(a);
            }
        }
    }
    sort(v.begin(),v.end());
    for (int i=0;i<s.size();i++)
    {
        cout<<v[i];
    }
    return 0;
}
