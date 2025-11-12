#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string b;
int s=0,sum=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    for(int i=0;i<b.size();i++){
        if(b[i]>='0'&& b[i]<='9'){
            s=int(b[i]-48);
            sum++;
            a[sum]=s;
        }
    }
    sort(a+1,a+1+sum,greater<int>());
    for(int i=1;i<=sum;i++){
        cout<<a[i];
    }
    return 0;
}
