#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000000];
    string a;
    long long s1=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
        //if(a[i]=='0'&&a[i]=='1'&&a[i]=='2'&&a[i]=='3'&&a[i]=='4'&&a[i]=='5'&&a[i]=='6'&&a[i]=='7'&&a[i]=='8'&&a[i]=='9'){
            s[i]=a[i];
            s1++;
        }
    }
    sort(s,s+s1,cmp);
    for(int i=0;i<s1;i++){
        cout<<s[i];
    }
}
