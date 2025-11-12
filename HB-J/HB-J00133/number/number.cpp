#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,ans="",tmdccf;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans+=s[i];
        }
    }
    int a[10]={0};
    for(int i=0;i<ans.length();i++){
        if(ans[i]=='0')a[0]++;
        else if(ans[i]=='1')a[1]++;
        else if(ans[i]=='2')a[2]++;
        else if(ans[i]=='3')a[3]++;
        else if(ans[i]=='4')a[4]++;
        else if(ans[i]=='5')a[5]++;
        else if(ans[i]=='6')a[6]++;
        else if(ans[i]=='7')a[7]++;
        else if(ans[i]=='8')a[8]++;
        else if(ans[i]=='9')a[9]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
             cout<<i;
        }
    }
    return 0;
}
