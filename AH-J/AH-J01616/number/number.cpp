#include<bits/stdc++.h>
#define long long
using namespace std;

const int dd=1e6+5;
char anss[dd];

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>=48&&s[i]<=57){
            anss[ans]=s[i];
            ans++;
        }
    }
    char zb;
    //sort(anss.assign(),anss.end());
    for(int i=0;i<=ans-1;i++){
        for(int j=i;j>0;j--){
            if(anss[j]>anss[j-1]){
                zb=anss[j-1];
                anss[j-1]=anss[j];
                anss[j]=zb;
            }
        }
    }
    for(int i=0;i<ans;i++){
        cout<<anss[i];
    }

    return 0;
}
