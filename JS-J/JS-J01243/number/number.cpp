#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    string s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[num]=s[i];
            num++;
        }
    }
    sort(a,a+num,cmp);
    for(int i=0;i<num;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
