#include<bits/stdc++.h>
using namespace std;
long long a[15],b=2;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long  i=0;i<s.size();i++){
        if(isdigit(int(s[i]))){
            a[int(s[i])-48]++;
        }
    }
    if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
        cout<<0<<endl;
    }
    else{
        for(int i=9;i>=0;i--){
            for(long long j=1;j<=a[i];j++){
                cout<<i;
            }
        } 
        cout<<endl;   
    }
    
    return 0;
}