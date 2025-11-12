#include<bits/stdc++.h>
using namespace std;
int a[1000010],j=0;
string s;
char c;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]<='9' && s[i]>='0'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a,a+1000009,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
