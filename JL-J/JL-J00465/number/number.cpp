#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number4.in","r",stdin);
    freopen("number.out","w",stdout);
    int k=0;
    cin>>s;
    int l=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+k+1,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
