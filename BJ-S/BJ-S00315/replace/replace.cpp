#include<iostream>
#include<vector>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2;
int main(void)
{
//    freopen("replace.in","r",stdin);
//    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;++i)
    {
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){printf("0\n");continue;}
        ans=0;
        int l=t1.length(),x,y;
        vector<int> loc['z'+1];
        for(int i=0;i<l;++i)if(t1[i]!=t2[i]){x=i;break;}
        for(int j=l-1;j>x;--j)if(t1[j]!=t2[j]){y=j;break;}
        for(int i=0;i<l;++i)loc[t1[i]].push_back(i);
        for(int f=1;f<=n;++f)
        {
            for(int i=0;i<loc[s1[f][0]].size()&&loc[s1[f][0]][i]+s1[f].length()-1<l;++i)
            {
                int p=loc[s1[f][0]][i];
                if(p<=x&&p+s1[f].length()-1>=y&&
                   t1.substr(p,s1[f].length())==s1[f]&&
                   t2.substr(p,s2[f].length())==s2[f])//可替换
                    ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
