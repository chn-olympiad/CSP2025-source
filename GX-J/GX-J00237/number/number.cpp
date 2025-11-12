#include<bits/stdc++.h>
using namespace std;
string str;
int cnt;
int a[1000005];
bool cmp(int a,int b){
    return b<a;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0')a[i]=0,cnt++;
        else if(str[i]=='1')a[i]=1,cnt++;
        else if(str[i]=='2')a[i]=2,cnt++;
        else if(str[i]=='3')a[i]=3,cnt++;
        else if(str[i]=='4')a[i]=4,cnt++;
        else if(str[i]=='5')a[i]=5,cnt++;
        else if(str[i]=='6')a[i]=6,cnt++;
        else if(str[i]=='7')a[i]=7,cnt++;
        else if(str[i]=='8')a[i]=8,cnt++;
        else if(str[i]=='9')a[i]=9,cnt++;
    }
    sort(a,a+cnt+1,cmp);
    for(int i=0;i<cnt;i++)cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
