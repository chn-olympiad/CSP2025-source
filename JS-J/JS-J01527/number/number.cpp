#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt=1;
void sort(){
    for(int i=1;i<cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    return;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[cnt++]=int(s[i]-'0');
        }
    }
    cnt--;
    sort();
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
 return 0;
}

