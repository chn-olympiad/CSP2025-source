#include<bits/stdc++.h>
using namespace std;
int s[10];
void f(int x){
    if(x<0)
        return;
    for(int i=0;i<s[x];i++){
        cout<<x;
    }
    f(x-1);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
        {
            s[0]++;
        }
        if(a[i]=='1')
        {
            s[1]++;
        }
        if(a[i]=='2')
        {
            s[2]++;
        }
        if(a[i]=='3')
        {
            s[3]++;
        }
        if(a[i]=='4')
        {
            s[4]++;
        }
        if(a[i]=='5')
        {
            s[5]++;
        }
        if(a[i]=='6')
        {
            s[6]++;
        }
        if(a[i]=='7')
        {
            s[7]++;
        }
        if(a[i]=='8')
        {
            s[8]++;
        }
        if(a[i]=='9')
        {
            s[9]++;
        }
    }
    f(9);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
