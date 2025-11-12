#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    int a[len+5];
    int k=1,cnt=0;
    for(int i=0;i<=len-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
                a[k]=int(s[i]-'0');
                cnt++;
                k++;
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
