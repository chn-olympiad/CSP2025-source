#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;int a[1000005],sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            sum++;
            a[sum]=int(s[i])-48;
            //cout<<a[i]<<endl;
        }
    }
    //for(int i=0;i<sum;i++)
    //       cout<<a[i];
    sort(a+1,a+sum+1,cmp);
    for(int i=1;i<=sum;i++)
        cout<<a[i];
    return 0;
}
