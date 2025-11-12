#include<iostream>
#include<map>
using namespace std;
map<string,int> mp1;
map<int,string> mp2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        mp1[s1]=i;
        mp2[i]=s2;
    }
    while(q--)
    {
        int cnt=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<"0"<<endl;
            continue;
        }
        int len=t1.size();
        t1=" "+t1;
        t2=" "+t2;
        for(int i=1;i<=len;i++)
        {
            for(int j=1;i+j-1<=len;j++)
            {
                if(t1.substr(1,i-1)==t2.substr(1,i-1)&&t1.substr(i+j)==t2.substr(i+j))
                {
                    string x=t1.substr(i,j),y=t2.substr(i,j);
                    if(mp1[x]!=0)
                    {
                        if(mp2[mp1[x]]==y) cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
