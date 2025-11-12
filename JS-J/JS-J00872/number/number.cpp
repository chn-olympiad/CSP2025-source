#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=1;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k-1;i++){
        cout<<a[i];
    }
    return 0;
}
