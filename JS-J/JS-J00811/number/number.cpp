#include<bits/stdc++.h>
using namespace std;
long long shu[1000005],l;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            shu[++l]=int(s[i]-'0');
        }
    }
    //for(int i=1;i<=l;i++)cout<<shu[i]<<" ";
    //sort(shu+1,shu+1+l);
    for(int i=l;i>=1;i--)cout<<shu[i];
    return 0;
}
