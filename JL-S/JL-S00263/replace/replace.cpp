#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    char s1[201],s2[201],t1[201],t2[201];
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
    {
        char d1='a',d2='a',f1='a',f2='a';
        int number=0,score=0;
        cin>>t1[i];
        cin>>t2[i];
        for(int j=1;j<=n;j++)
        {
            if((t1[i]==s1[j])&&(t2[i]==s2[j]))
            {
                score++;
            }
        }
        int right=sizeof(t1);
        int left=1;
        while(left<=right)
        {
            if(t1[i]&left!=t2[i]&left)
            {
                strcat(d1,t1[i]);
                strcat(d2,t2[i])
            }
            left++;
        }
        for(int j=1;j<=n;j++)
        {
            strcat(f1,s1[j]);
            strcat(f2,s2[j])
            if((d1==f1)&&(d2==f2))
            {
                score++;
            }
        }
        cout<<score<<endl;
    }
}
