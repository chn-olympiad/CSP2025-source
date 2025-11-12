#include<bits/stdc++.h>
using namespace std;
int n,q,ans,lent,flag,stt;
string s[2010],t[2010];
string qs,qt;
string cs[2010],ct[2010];
string cqs,cqt;
int len[2010],st[2010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>t[i];
        int idx=0;
        for(int j=0;j<s[i].size();j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(s[i][j]!=t[i][j])
            {
                if(!idx)
                {
                    st[i]=j;
                }
                //cout<<idx<<" "<<s[i][j]<<" "<<cs[i][0]<<endl;
                cs[i][idx]=s[i][j];
                ct[i][idx]=t[i][j];
                idx++;
            }
            else
            {
                if(idx!=0)
                {
                    cs[i][idx]='0';
                    ct[i][idx]='0';
                    idx++;
                }
            }
        }
        len[i]=idx;
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<len[i];j++)
        {
            cout<<cs[i][j];
        }
        cout<<" ";
        for(int j=0;j<len[i];j++)
        {
            cout<<ct[i][j];
        }
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++)
    {
        ans=0;
        cin>>qs>>qt;
        if(qs.size()!=qt.size())
        {
            cout<<0<<endl;
            continue;
        }
        int idx=0;
        for(int j=0;j<qs.size();j++)
        {
            if(qs[j]!=qt[j])
            {
                if(!idx)
                {
                    stt=j;
                }
                cqs[idx]=qs[j];
                cqt[idx]=qt[j];
                idx++;
            }
            else
            {
                if(idx!=0)
                {
                    cqs[idx]='0';
                    cqt[idx]='0';
                    idx++;
                }
            }
        }
        lent=idx;
        /*cout<<stt<<endl;
        for(int j=0;j<lent;j++)
        {
            cout<<cqs[j];
        }
        cout<<" ";
        for(int j=0;j<lent;j++)
        {
            cout<<cqt[j];
        }
        cout<<endl;*/
        for(int k=1;k<=n;k++)
        {
            //cout<<k<<" A "<<lent<<" "<<len[k]<<endl;
            flag=1;
            if(lent==len[k])
            {
                flag=0;
                for(int j=0;j<lent;j++)
                {
                    if(cqs[j]!=cs[k][j]||cqt[j]!=ct[k][j])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            else if(lent>len[k])
            {
                flag=0;
                for(int j=0;j<len[k];j++)
                {
                    //cout<<j<<" "<<cqs[j]<<" "<<cqt[j]<<" B "<<cs[k][j]<<" "<<ct[k][j]<<endl;
                    if(cqs[j]!=cs[k][j]||cqt[j]!=ct[k][j])
                    {
                        flag=1;
                        break;
                    }
                }
                for(int j=len[k];j<lent;j++)
                {
                    if(cqs[j]!='0'||cqt[j]!='0')
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
            {
                for(int j=stt-st[k],l=0;j<qs.size(),l<s[k].size();j++,l++)
                {
                    //cout<<j<<" "<<qs[j]<<" "<<qt[j]<<" C "<<l<<" "<<s[k][l]<<" "<<t[k][l]<<endl;
                    if(s[k][l]!=qs[j]||t[k][l]!=qt[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
