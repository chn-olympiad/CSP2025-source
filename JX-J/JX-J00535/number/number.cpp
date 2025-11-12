#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            a[sum]=0;
            sum++;
        }
        if(s[i]=='1'){
            a[sum]=1;
            sum++;
        }
        if(s[i]=='2'){
            a[sum]=2;
            sum++;
        }
        if(s[i]=='3'){
            a[sum]=3;
            sum++;
        }
        if(s[i]=='4'){
            a[sum]=4;
            sum++;
        }
        if(s[i]=='5'){
            a[sum]=5;
            sum++;
        }
        if(s[i]=='6'){
            a[sum]=6;
            sum++;
        }
        if(s[i]=='7'){
            a[sum]=7;
            sum++;
        }
        if(s[i]=='8'){
            a[sum]=8;
            sum++;
        }
        if(s[i]=='9'){
            a[sum]=9;
            sum++;
        }
    }
    //cout<<sum;
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
