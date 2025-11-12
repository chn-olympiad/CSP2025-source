#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector <char> data;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            data.push_back(s[i]);
        }
    }
    for(int i=0;i<data.size()-1;i++)
    {
        for(int j=i+1;j<data.size();j++)
        {
            char a=data[i];
            if(data[i]<data[j])
            {
                data[i]=data[j];
                data[j]=a;
            }
        }
    }
    int zd=0;
    for(int i=0;i<data.size();i++)
    {
        zd=zd*10+int(data[i]-'0');
    }
    cout<<zd;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
