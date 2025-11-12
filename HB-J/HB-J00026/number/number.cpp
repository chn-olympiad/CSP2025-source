#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[10005];
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size(string s)t,num;
    for(int i=1,j=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
        t=j;
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            if(a[i]>a[j]){
            a[i]=num;
            a[i]=a[j];
            a[j]=num;
        }
        }
    }
    for(int i=1;i<=t;i++){
        cout<<a[i];
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
