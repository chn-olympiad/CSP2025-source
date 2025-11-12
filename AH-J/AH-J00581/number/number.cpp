#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
char a[1000005],cnt=0;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n= s.size();
    for(int i=0;i<=n;i++){
        if(s[i]-'0'>=0 && s[i]-'9'<=0){
            a[i]=s[i];
            cnt++;
        }
    }
    sort(a+0,a+n+1,cmp);
    for(int i=0;i<cnt;i++){
        cout << a[i];
    }
    return 0;
}
