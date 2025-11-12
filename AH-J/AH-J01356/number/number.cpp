#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[10001],b=0,j;
    string s;
    cin>>s;
    for(int i=0;i<=s.length();){
        if(s[i]<='9'&&s[i]>='0'){
            a[j]=s[i];
            if(a[j]>a[j-1]&&j>0){
                b=a[j];
                a[j]=a[j-1];
                a[j-1]=b;

            }
            j++;
        }
        i++;
    }
    sort(a+0,a+j);
    for(int j=0;j<=10001;j++){
        cout<<a[j];
    }
    return 0;
}
