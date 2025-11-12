#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s,a;

int n=0,num=0,sum=0;
cin>>s;
for(int i=0;i<=s.size();i++){
    if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
        n++;
        a[n]=s[i];

    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++){
        if(a[j]<a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
}
for(int i=1;i<=n;i++){
    cout<<a[i];

}

return 0;
}
