#include<bits/stdc++.h>
using namespace std;
string a;
long long s[1000010],ans=0,b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(int(a[i])<97){
            ans++;
            if(a[i]=='1')b=1;
            else if(a[i]=='2')b=2;
            else if(a[i]=='3')b=3;
            else if(a[i]=='4')b=4;
            else if(a[i]=='5')b=5;
            else if(a[i]=='6')b=6;
            else if(a[i]=='7')b=7;
            else if(a[i]=='8')b=8;
            else if(a[i]=='9')b=9;
            else if(a[i]=='0')b=0;
            s[ans]=b;
        }
    }
    sort(s+1,s+ans+1);
    for(int i=ans;i>=1;i--){
        cout<<s[i];
    }
    return 0;
}
