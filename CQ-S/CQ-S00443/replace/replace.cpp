#include<bits/stdc++.h>
using namespace std;
#define mt make_tuple
#define LL unsigned long long
set<LL> st;
int n,q,cnt;
string ch1,ch2;
vector<LL> v[5000005];
map<tuple<LL,LL,LL>,int> mp1;
map<tuple<LL,LL,LL,LL>,int> mp2;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n+q;i++){
        cin>>ch1>>ch2;
        int len=ch1.length(),l=0,r=len-1;
        while(l<len&&ch1[l]==ch2[l])  l++;
        if(l==len)  continue;
        while(ch1[r]==ch2[r])  r--;
        LL sum1=0,sum2=0,sum3=0,sum4=0,po=1;
        for(int j=0;j<l;j++)  sum1=sum1*131+ch1[j];
        for(int j=l;j<=r;j++)  sum2=sum2*131+ch1[j];
        for(int j=l;j<=r;j++)  sum3=sum3*131+ch2[j];
        for(int j=r+1;j<len;j++)  sum4=sum4*131+ch2[j];
        if(i<=n){
            if(!mp1.count({sum1,sum2,sum3}))
                mp1[{sum1,sum2,sum3}]=cnt++;
            v[mp1[{sum1,sum2,sum3}]].push_back(sum4);
        }
        else{
            sum1=0,st.clear(),sum4=0;int ans=0;
            for(int j=r;j<len;j++){
                if(j!=r)  sum4=sum4*131+ch1[j];
                st.insert(sum4);
            }
            for(int j=l;j>=0;j--){
                if(j!=l)  sum1+=ch1[j]*po,po*=131;
                if(mp2.count({sum1,sum2,sum3,sum4})){
                    ans+=mp2[{sum1,sum2,sum3,sum4}];
                    continue;
                }
                if(!mp1.count({sum1,sum2,sum3})){
                    mp2[{sum1,sum2,sum3,sum4}]=0;
                    continue;
                }
                int vnum=mp1[{sum1,sum2,sum3}],sum=0;
                for(auto x:v[vnum])  if(st.count(x))  sum++;
                ans+=sum,mp2[{sum1,sum2,sum3,sum4}]=sum;
            }
            cout<<ans<<"\n";
        }
    }
}