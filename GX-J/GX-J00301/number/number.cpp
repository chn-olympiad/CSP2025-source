#include<bits/stdc++.h>
using namespace std;
char a[100]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=0;
    for(int i=0;i<s.size();i++){
        if(!(s[i]<=123&&s[i]>=97)){
            a[n]=s[i];
            n+=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            int x;
            if(a[j-1]<a[j]){
                x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
