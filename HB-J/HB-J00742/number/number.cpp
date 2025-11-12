#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
int arr[MAXN] = {0};
int len = 0;
string s;
struct cmp{
    inline bool operator()(int &a,int &b)const{
        return a>b;
    }
};
int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    cin>>s;
    for(int i=0;i<(int)s.size();++i){
        if(isdigit(s[i])){
            arr[len] = s[i]-'0';
            len++;
        }
    }
    sort(arr,arr+len,cmp());
    for(int i=0;i<len;++i){
        cout<<arr[i];
    }
    return 0;
}
