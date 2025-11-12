#include <fstream>
#include <vector>
using namespace std;
ifstream cin("replace.in");
ofstream cout("replace.out");
const int NR=2e5+5;
string s[NR][2],str1,str2;
int l[NR],n,q,ans,len,beg,edk;
vector<int> nxt[NR];
int main()
{
    cin>>n>>q;
    for(int k=1;k<=n;k++)
    {
        //cout<<"ty:"<<k<<endl;
        cin>>s[k][1]>>s[k][0];
        l[k]=s[k][1].length();
        s[k][1]="*"+s[k][1];
        s[k][0]="*"+s[k][0];
        nxt[k].push_back(-1);
        nxt[k].push_back(0);
        int j=0;
        for(int i=2;i<=l[k];i++)
        {
            while(s[k][1][i]==s[k][1][j+1])
            {
                i++,j++;
                //cout<<i<<" "<<j<<endl;
            }
            while(i<=l[k]&&j>0&&s[k][1][i]!=s[k][1][j+1])
            {
                j=nxt[k][j];
                //cout<<i<<j<<endl;
            }
            if(s[k][1][i]==s[k][1][j+1])
                j++;
            //cout<<j<<endl;
            nxt[k].push_back(j);
            //cout<<nxt[k][i-1]<<endl;
        }
    }
    while(q--)
    {
        ans=0;
        cin>>str1;
        cin>>str2;
        int len=str1.length();
        //cout<<len<<endl;
        str1="*"+str1;
        str2="*"+str2;
        beg=len,edk=0;
        for(int i=1;i<=len;i++)
        {
            if(str1[i]!=str2[i])
            {
                beg=min(beg,i);
                edk=max(edk,i);
            }
        }
        //cout<<"rt:"<<beg<<" "<<edk<<endl;
        for(int k=1;k<=n;k++)
        {
            int j=0;
            for(int i=1;i<=len;i++)
            {
                while(str1[i]==s[k][1][j+1]&&i<=len)
                    i++,j++;
                int lj=j;
                //cout<<i<<" "<<j<<endl;
                if(j==l[k])
                {
                    if(i>len)
                        i=len;
                    //cout<<"l"<<k<<endl;;
                    //cout<<i<<j<<endl;
                    if(i-j+1>beg)
                        continue;
                    if(i-j+1<=beg&&i>=edk)
                    {
                        //cout<<"op\n";
                        bool flg=true;
                        for(int op=1;op<=l[k];op++)
                        {
                            if(s[k][0][op]!=str2[i-j+op])
                            {
                                flg=false;
                                //cout<<s[k][0][op]<<' '<<str2[i-j+op]<<endl;
                            }
                        }
                        ans+=flg;
                    }
                }
                while(i<=len&&j>0&&str1[i]!=s[k][1][j+1])
                    j=nxt[k][j];
                if(str1[i]==s[k][1][j+1])
                    j++;
                i=i-(lj-j)+1;
                //cout<<i<<" "<<j<<endl;
                if(j==l[k])
                {
                    if(i-j+1>beg)
                        break;
                    if(i-j+1<=beg&&i>=edk)
                    {
                        bool flg=true;
                        for(int op=1;op<=l[k];op++)
                        {
                            if(s[k][0][op]!=str2[i-j+1+op])
                                flg=false;
                        }
                        ans+=flg;
                    }
                }
            }
        }
        if(ans==0)
            cout<<ans<<endl;
        else
            cout<<ans+1<<endl;
    }
    return 0;
}
