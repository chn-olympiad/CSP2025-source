#include<bits/stdc++.h>
using namespace std;
multiset<char> st;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num=0;
    char c;
    do
    {
        c=getchar();
        if(isdigit(c))
        {
            st.insert(c);
        }
    }while(c!='\n');
    multiset<char>::reverse_iterator it;
    for(it=st.rbegin();it!=st.rend();it++)
    {
        putchar( (*it) );
    }
    return 0;
}
