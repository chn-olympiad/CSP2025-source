#include<bits/stdc++.h>
using namespace std;
char cmp(char a,char b)
{

    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string st;
    cin>>st;
    vector<char> vi;
    for(int i=0;i<st.size();i++)
    {
        if(st[i]=='0'||st[i]=='1'||st[i]=='2'||st[i]=='3'||st[i]=='4'||st[i]=='5'||st[i]=='6'||st[i]=='7'||st[i]=='8'||st[i]=='9')
        {
            vi.push_back(st[i]);
        }
    }
    sort(vi.begin(),vi.begin()+vi.size(),cmp);
    for(int i=0;i<vi.size();i++)
    {
        cout<<vi[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
