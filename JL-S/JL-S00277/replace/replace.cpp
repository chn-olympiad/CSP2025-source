#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>m;
unordered_map<string,string>::iterator r;
int n,q;
long long cnt=0;
string str1,str2,lft1,rit1,mid1,lft2,rit2,mid2;
bool not_at_all()
{
    bool ret=true;
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]==str2[i])
            ret=false;
        //cout<<str1[i]<<' '<<str2[i]<<endl;
    }
    return ret;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>str1>>str2;
        m.insert(make_pair(str1,str2));
    }
    while(q--)
    {
        cnt=0;
        cin>>str1>>str2;
        if(str1.size()!=str2.size()||not_at_all())
        {
            printf("0\n");
            continue;
        }
        for(int i=0;i<str1.size();i++)
        {
            for(int j=i;j<str1.size();j++)
            {
                lft1.clear();
                rit1.clear();
                mid1.clear();
                lft2.clear();
                mid2.clear();
                rit2.clear();
                for(int k=0;k<i;k++)
                {
                    lft1+=str1[k];
                    lft2+=str2[k];
                }
                for(int k=i;k<=j;k++)
                {
                    mid1+=str1[k];
                    mid2+=str2[k];
                }
                for(int k=j+1;k<str1.size();k++)
                {
                    rit1+=str1[k];
                    rit2+=str2[k];
                }
                //mid1+='\0';
                //mid2+='\0';
                //cout<<i<<' '<<j<<' '<<lft1<<' '<<mid1<<' '<<rit1<<'\t'<<lft2<<' '<<mid2<<' '<<rit2;
                r=m.find(mid1);
                if(r==m.end())
                {
                    //cout<<endl;
                    continue;
                }
                if((r->second)==mid2)
                {
                    cnt++;
                    //cout<<" Our success!";
                }
                //cout<<endl;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
