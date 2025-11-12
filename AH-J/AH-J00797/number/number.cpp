#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    string s;
    long long i,cnt=0;
    char* a=new char[1000000];
    cin>>s;
    for(i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[++cnt]=s[i];
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(i=1;i<=cnt;i++){
        cout<<a[i];
    }
    cout<<endl;
    delete a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
