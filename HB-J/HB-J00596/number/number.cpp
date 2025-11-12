#include<bits/stdc++.h>
using namespace std;

int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int cnt=0;
    int a[s.size()]={0};
    int size =s.size();

    for(int i=0;i<size;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[i]=int(s[i])-48;
           // cout <<a[i]<<endl;
        }else{
            cnt++;
        }
    }
    sort(a,a+size);
    //cout << a[1];
    for(int i=size-1;i>=cnt;i--){
        if(a[i]==0||a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9){
            cout << a[i];
        }
    }
    return 0;
}
// 114514
