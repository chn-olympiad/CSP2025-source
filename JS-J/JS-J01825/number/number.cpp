#include<bits/stdc++.h>
using namespace std;
string sen;
int num[100005]={0},cnt=0;
int main(){
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    cin>>sen;
    for(int i=0;i<sen.length();i++)
    {
        if(sen[i]>='0'&&sen[i]<='9')
        {
            num[cnt]=sen[i]-'0';
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int i=cnt-1;i>=0;i--)
        cout<<num[i];
    return 0;
}
