#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FRR freopen("number.in","r",stdin)
#define FRW freopen("number.out","w",stdout)
bool cmp(const int &x,const int &y){
    return x>y;
}
signed main(){
    FRR;
    FRW;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    sort(str.begin(),str.end(),cmp);
    for(int i=0;i<str.size();i++) if(str[i]>='0'&&str[i]<='9') cout<<str[i];
	return 0;
}
