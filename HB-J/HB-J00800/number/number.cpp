#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=0;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
//    cout<<k<<endl;
//    for(int i=0;i<k;i++){
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    sort(a+0,a+k,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
