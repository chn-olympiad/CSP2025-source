#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100]={0,0,0,0,0,0,0,0,0,0,0};
long long sum=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            a[0]+=1;
        }else if(s[i]=='1'){
            a[1]+=1;
        }else if(s[i]=='2'){
            a[2]+=1;
        }else if(s[i]=='3'){
            a[3]+=1;
        }else if(s[i]=='4'){
            a[4]+=1;
        }else if(s[i]=='5'){
            a[5]+=1;
        }else if(s[i]=='6'){
            a[6]+=1;
        }else if(s[i]=='7'){
            a[7]+=1;
        }else if(s[i]=='8'){
            a[8]+=1;
        }else if(s[i]=='9'){
            a[9]+=1;
        }else{
            continue;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>=1;j--){
            cout<<i;
        }
    }
    return 0;
}
