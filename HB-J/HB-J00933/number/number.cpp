#include<bits/stdc++.h>
using namespace std;
unsigned long long sum,num;
unsigned long long a[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<=s.size()+1;i++){
        if(s[i]>='0' && s[i]<='9'){
                num+=1;
                a[num]=int(s[i])-48;
        }
    }
    sort(a+1,a+1+num);
    for(int i=num;i>=1;i--){
        for(int j=1;j<i;j++){
            a[i]*=10;
        }
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
