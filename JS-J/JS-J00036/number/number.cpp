#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001],sum=0;
string s;
bool mycmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);


    cin>>s;
    for(int i=0;i<s.size();i++){
        int m=s[i]-'0';
        //cout<<m<<" ";
        if(m>=0&&m<=9){
            a[sum]=m;
            sum++;
        }
    }
    sort(a,a+sum,mycmp);
    for(int i=0;i<sum;i++) cout<<a[i];
    cout<<endl;
    return 0;
}
