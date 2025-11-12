#include<bits/stdc++.h>
using namespace std;
string s;
int num[1001],sum=0;
bool cmp(int a,int b){
        return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
                num[sum]=int(s[i]-'0');
                sum++;
        }
    }
    sort(num,num+l+1,cmp);
    for(int i=0;i<sum;i++){
        cout<<num[i];
    }
    return 0;
}
