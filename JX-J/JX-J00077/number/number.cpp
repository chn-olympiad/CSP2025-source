#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],ans;
int main(){
    freopen("number.in","w","stdin")
    freopen("number.out","r","stdout")
    cin>>s;
    int b=s.length(),c=1;
    for(int i=1;i<=b;i++){
        if(s<="9"&&s>="0"){
            a[c]=s;
            c++;
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=i+1;j<=c;j++){
            if(a[i]<a[j]) a[i]=a[j];
        }
    }
    for(int i=1;i<=c;i++){
        ans=ans*10+a[i];
    }
    cout<<ans<<endl;
    fclose("stdin")
    fclose("stdout")
    return 0;
}
