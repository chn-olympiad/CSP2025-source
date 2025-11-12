#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t=0;
    int cnt=0;
    int lens=s.size();
    int a[lens]={0};
    for(int i=0;i<lens;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t=s[i]-'0';
            cnt++;
        }
        if(t>=0&&t<=9){
            a[cnt]=t;
        }
    }
    sort(a,a+cnt+1,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
       return 0;
}
