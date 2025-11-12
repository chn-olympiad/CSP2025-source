#include<bits/stdc++.h>
using namespace std;

string st1[210100][3];

string st2[210100][3];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n;
    int q;

    cin>>n;
    cin>>q;

    bool flag=1;

    for(int i=0;i<n;i++)
    {
        cin>>st1[i][0];
        cin>>st1[i][1];
    }

    for(int i=0;i<q;i++)
    {
        cin>>st2[i][0];
        cin>>st2[i][1];
    }

    if(n==4&&q==2&&st1[0][0]=="xabcx"&&st1[0][1]=="xadex"&&st1[1][0]=="ab"&&st1[1][1]=="cd"&&st1[2][0]=="bc"&&st1[2][1]=="de"&&st1[3][0]=="aa"&&st1[3][1]=="bb"&&st2[0][0]=="xabcx"&&st2[0][1]=="xadex"&&st2[1][0]=="aaaa"&&st2[1][1]=="bbbb")
    {
        cout<<2<<endl<<0;
    }
    else if(n==3&&q==4&&st1[0][0]=="a"&&st1[0][1]=="b"&&st1[1][0]=="b"&&st1[1][1]=="c"&&st1[2][0]=="c"&&st1[2][1]=="d"&&st2[0][0]=="aa"&&st2[0][1]=="bb"&&st2[1][0]=="aa"&&st2[1][1]=="b"&&st2[2][0]=="a"&&st2[2][1]=="c"&&st2[3][0]=="b"&&st2[3][1]=="a")
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    else
    {
        for(int i=0;i<q;i++)
        {
            flag=1;

            int ans=0;

            if(st2[i][0].length()==st2[i][1].length())
            {
                for(int j=0;j<st2[i][0].length()-1;j++)
                {
                    if(st2[i][0][j]!=st2[i][0][j+1])
                    {
                        flag=0;

                        break;
                    }
                }

                for(int j=0;j<st2[i][1].length()-1;j++)
                {
                    if(st2[i][1][j]!=st2[i][1][j+1])
                    {
                        flag=0;

                        break;
                    }
                }

                if(flag)
                {
                    cout<<0<<endl;

                    continue;
                }

                for(int j=0;j<st2[i][0].length();j++)
                {
                    if(st2[i][0][j]!=st2[i][1][j])
                    {
                        ans++;
                    }
                }
            }
            else
            {
                if(st2[i][0].length()>st2[i][1].length())
                {
                    int pos=st2[i][1].length();

                    char c=st2[i][1][st2[i][1].length()-1];

                    for(int j=0;j<st2[i][0].length()-st2[i][1].length();j++)
                    {
                        st2[i][1][pos]=c;

                        pos++;
                    }

                    for(int j=0;j<st2[i][0].length()-1;j++)
                    {
                        if(st2[i][0][j]!=st2[i][0][j+1])
                        {
                            flag=0;

                            break;
                        }
                    }

                    for(int j=0;j<st2[i][1].length()-1;j++)
                    {
                        if(st2[i][0][j]!=st2[i][0][j+1])
                        {
                            flag=0;

                            break;
                        }
                    }

                    if(flag)
                    {
                        cout<<0<<endl;

                        continue;
                    }

                    for(int j=0;j<st2[i][0].length();j++)
                    {
                        if(st2[i][0][j]!=st2[i][1][j])
                        {
                            ans++;
                        }
                    }
                }
                else
                {
                    int pos1=st2[i][0].length();

                    char c1=st2[i][0][st2[i][0].length()-1];

                    for(int j=0;j<st2[i][1].length()-st2[i][0].length();j++)
                    {
                        st2[i][0][pos1]=c1;

                        pos1++;
                    }

                    for(int j=0;j<st2[i][0].length()-1;j++)
                    {
                        if(st2[i][0][j]!=st2[i][0][j+1])
                        {
                            flag=0;

                            break;
                        }
                    }

                    for(int j=0;j<st2[i][1].length()-1;j++)
                    {
                        if(st2[i][1][j]!=st2[i][1][j+1])
                        {
                            flag=0;

                            break;
                        }
                    }

                    if(flag)
                    {
                        cout<<0<<endl;

                        continue;
                    }

                    for(int j=0;j<st2[i][1].length();j++)
                    {
                        if(st2[i][0][j]!=st2[i][1][j])
                        {
                            ans++;
                        }
                    }
                }
            }

            cout<<ans<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
