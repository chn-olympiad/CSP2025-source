#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000006];
int n=0;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(a,-1,sizeof(a));
    cin>>s;
    for(int i=0;i<s.size();i++){
        //cout<<"t:"<<i<<endl;
        if(/*isdigit(s[i])*/s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            n++;
            a[n]=int(s[i]-'0');
            //cout<<"i:"<<i<<" a[n]:"<<a[n]<<" n:"<<n<<endl;
        }
    }
    sort(a+1, a+n+1);
    for(int i=n;i>0;i--){
        cout/*<<"a["<<i<<"]:"*/<<a[i];
    }
    //cout<<"s:"<<s;
    return 0;
}
