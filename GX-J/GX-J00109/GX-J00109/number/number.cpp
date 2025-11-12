#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
string n;
cin>>n;
int m[10000],l=0;
for(int i=0;i<10000;i++){
    m[i]=-1;
}for(int i=0;n[i]!='\0';i++){
if(n[i]>='0'&&n[i]<='9'){
    m[l]=n[i]-'0';l++;
}
}
for(int i=0;i<l;i++){
    for(int t=i+1;t<l;t++){
        if(m[i]<m[t]){
            swap(m[i],m[t]);
        }
    }
    cout<<m[i];
}
    return 0;
}
