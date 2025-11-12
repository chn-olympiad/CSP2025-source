#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=1e6+3999;
int n,c,m;
string s;


    long long ans=0;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool f=0;
    for(int i=0;i<s.length();i++)if(s[i]=='0')f=1;
    if(!f){
        ans=n;
    }else{
    if(s[0]=='0')ans++;
    for(int i=1;i<s.length();i++){
        if(s[i]!='0'){
            if(s[i-1]=='0'){
                s[i]='0';
            }
            else{
                ans++;
            }
        }
    }
    }
    for(long long w=ans-1;w>1;w--){
            if(w!=0){
                 ans%=9982444353;

                 ans=ans*w;
                 ans%=9982444353;
            }

    }
    cout<<ans/m;











    return 0;
}
