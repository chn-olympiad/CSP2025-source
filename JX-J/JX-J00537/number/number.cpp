#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
char n[]={'0','1','2','3','4','5','6','7','8','9','0'};
int cnt=1,c[1005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<=l;i++){
        for(int j=1;j<=10;j++){
            if(s[i]==n[j]){
                a[cnt]=s[i];
                cnt++;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=i;j<=cnt;j++){
            if(a[i]<a[j]) swap(a[i],a[j]);
        }
    }
    for(int i=1;i<cnt;i++){
        c[i]=a[i];
        cout<<c[i]-48;
    }

    return 0;
}
