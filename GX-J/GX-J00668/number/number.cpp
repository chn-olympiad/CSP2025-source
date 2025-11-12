#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);




    string s;
    long long arr[114514]={};
    cin>>s;
    for(long long i=0;i<=s.size();i++){
        if(int(s[i])-57>0){
            continue;
        }
        else{
            arr[i]=s[i];
        }
    }
    sort(arr,arr+s.size());
    for(long long i=s.size()-1;i>=0;i--){
        if(arr[i]==0){
            continue;
        }
        cout<<arr[i]-48;
    }
    return 0;
}
