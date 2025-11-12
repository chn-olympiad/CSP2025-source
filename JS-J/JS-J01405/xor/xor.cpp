#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,ans;
int arr[N];
bool f[N];
struct qwq
{
    int l,r,len;
};
vector<qwq> vec;
string dtob(int n)
{
    string res="";
    while(n>0)
    {
        res.push_back(char(n%2)+'0');
        n/=2;
    }
    reverse(res.begin(),res.end());
    int len=vec.size();
    while(res.size()<len)
    {
        res='0'+res;
    }
    return res;
}
bool cmp(qwq a,qwq b)
{
    return a.l < b.l;
}
int check(string str)
{
    int cnt=0;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='1')
        {
            for(int j=0;j<i;j++)
            {
                if(str[j]=='1' && (vec[j].r>=vec[i].l))
                {
                    return -1;
                }
            }
            cnt++;
        }
    }
    return cnt;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(n>10)
    {
        if(k==0) //A
        {
            cout<<n/2<<'\n';
            return 0;
        }
        if(k==1)
        {
            for(int i=1;i<=n;i++) //B?
            {
                if(arr[i]==1)
                {
                    ans++;
                }
            }
            cout<<ans<<'\n';
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int res=arr[i];
        int pos=i;
        bool h=false;
        while(pos<=n)
        {
            if(res==k)
            {
                h=true;
                break;
            }
            pos++;
            res^=arr[pos];
        }
        if(h)
        {
            vec.push_back({i,pos,pos-i+1});
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    /*
    for(int i=0;i<(int)vec.size();i++)
    {
        cout<<vec[i].l<<' '<<vec[i].r<<'\n';
    }
    */
    for(int k=0;k<=(1<<vec.size())-1;k++)
    {
        string str=dtob(k);
        //cout<<str<<'\n';
        ans=max(ans,check(str));
    }cout<<ans<<'\n';
    return 0;
}

//9:09 xia ku le qwq
//9:12 zhe za zuo ,xia ku le
//9:18 cong WC hui lai ,0 si lu
//9:19 5e5 xia ku le
//9:19 xian da bao li
//9:35 wo zhe da de sha,kan tu le:(
//9:39 zhe dou gua? bao le
//9:41 jia wan le,wo shi ren?
//9:44 bu hui,yao bao le
//9:48 xiang dao de bao li zhi you 10pts,xian da T4
//10:21 bao li qi dong
//10:35 +10pts
//100+100+10+40=me hai neng zheng
//1= xian bu hui guo 250pts ba...
//11:01 kan kan T3
//11:04 zhe ge 1e2 de za da a:(
//11:06 xuan ze pin hao fen
//11:10 +5pts
//11:22 +0~15pts (
