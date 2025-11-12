#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int s[1000100]={0},i=1;
    cin>>a;
    for(int j=0;j<a.size();j++){
        if(a[j]>='0'&&a[j]<='9'){
            s[i]=int(a[j]-'0');
            i++;
        }
    }
    //while(cin>>a){
        //if(a>='0'&&a<='9'){
            //s[i]=int(a-'0');
            //i++;
        //}
    //}
    sort(s+1,s+i);
    for(int j=i-1;j>0;j--){
        cout<<s[j];
    }
    return 0;
}
