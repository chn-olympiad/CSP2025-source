#include<bits/stdc++.h>
using namespace std;
int a[1000100],cnt;
bool cmp(int x,int y){
     return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char c:s)
        if(c>='0'&&c<='9')a[++cnt]=c-48;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
        cout<<a[i];
    return 0;
}
