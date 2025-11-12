#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int s1[1000005],a=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if('0'<=s[i] && s[i]<='9')
            s1[a++] = s[i] - '0';
    sort(s1+1,s1+a,cmp);
    if(s1[1]==0){
        cout<<"0\n";
        return 0;
    }
    for(int i=1;i<a;i++)
        cout<<s1[i];
    cout<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
