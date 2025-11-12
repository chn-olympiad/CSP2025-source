#include <bits/stdc++.h>

using namespace std;
string s;
const int N=1000010;
int n,a[N],id=0;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++id]=s[i]-'0';
        }
    }
    sort(a+1,a+1+id,cmp);
    for(int i=1;i<=id;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
