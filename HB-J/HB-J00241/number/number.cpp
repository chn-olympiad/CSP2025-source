#include<bits/stdc++.h>
#include<stdio.h>
bool cmp(int x,int y){
    if(x<y)
        return y>x;
    else
        return x>y;
    }
using namespace std;
int a[30];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int cnt;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[int(s[i]-'0')]++;
        }

    }

    sort(a+1,a+cnt+1,cmp);
    return 0;

}
