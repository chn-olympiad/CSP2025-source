#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int lens,a[1000005],cnt;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    lens=s.size();
    for(int i=0;i<lens;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=(s[i]-'0');
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
