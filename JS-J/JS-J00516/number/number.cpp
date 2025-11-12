#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
    return x>y;
}

void lesson(){
    cin>>s;
    int n=s.length(),j=1;
    for(int i=0;i<n;i++){
        if(s[i]-'0'<10&&s[i]-'0'>=0){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a+1,a+n+1,cmp);
    if(a[1]!=0){
        for(int i=1;i<j;i++){
            cout<<a[i];
        }

    }
    else{
        cout<<0;
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    lesson();
    return 0;
}

