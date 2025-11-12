#include<bits/stdc++.h>
using namespace std;
string s;
int a[100002],ans,l,cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
//    cout<<int(s[3])-48<<endl;
    for(int i=0;i<=s.size();i++){
        if(!(int(s[i])>=97&&s[i]<=122)){
            //cout<<s[i]<<endl;
            l++;
            a[l]=int(s[i])-48;
        }
    }
 //   cout<<a[2];
    for(int i=0;i<=l;i++){
        for(int j=i+1;j<=l;j++){
            if(a[i]<a[j]) swap(a[i],a[j]);
        }
    }

    for(int i=0;i<l-1;i++){
        printf("%d",a[i]);
    }
    return 0;
}
