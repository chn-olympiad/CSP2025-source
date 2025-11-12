#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
        return x>y;
}
int main(){
freopen("number.in","w",stdin);
freopen("number.out","r",stdout);
    cin>>s;
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]==s[i]-48;
        }
    }
    sort(a+1,a+1000010+1);
    for(int i=1;i<=1000010;i++){
        cout<<a[i];
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
