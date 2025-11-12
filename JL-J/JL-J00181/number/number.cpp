#include<bits/stdc++.h>;
using namespace std;
string s;
int a[1000000];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    int z=s.size();
    int b=z,g=0;
    for(int i=0;i<z;i++)
    {
        if(s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9||s[i]-'0'==0)
        {
            a[i]=s[i]-'0';
            if(a[i]<a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
        if(s[i]-'0'!=1||s[i]-'0'!=2||s[i]-'0'!=3||s[i]-'0'!=4||s[i]-'0'!=5||s[i]-'0'!=6||s[i]-'0'!=7||s[i]-'0'!=8||s[i]-'0'!=9||s[i]-'0'!=0)
            continue;
    }
    for(int i=0;i<z;i++)
        cout<<a[i]<<endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
