#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int h=s.size();
    int j=1;
    for(int i=0;i<h;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=(s[i]-'0');
            j++;
        }
    }
    j--;
    bool f1=0,f=1;
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--){
        if(f&&a[i]==0){
            continue;
        }else f=0;
        f1=1;
        cout<<a[i];
    }
    if(!f1) cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

