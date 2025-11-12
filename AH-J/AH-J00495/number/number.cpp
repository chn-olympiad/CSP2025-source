#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int ans=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++){
            if (int(s[i]>=48 && s[i]<=57)){
                a[ans]=int(s[i]);
                ans++;

            }
    }
    for (int i=0;i<ans;i++){
        for (int j=i+1;j<ans;j++){
            if (int(a[i])<int(a[j])){
                int changes=a[i];
                a[i]=a[j];
                a[j]=changes;
            }
        }
    }
    for (int i=0;i<ans;i++){
        cout<<a[i]-48;
    }
    return 0;
}
