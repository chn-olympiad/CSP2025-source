#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()+2];
    int j=1;
    stack<int>k;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a+1,a+j);
    for(int i=1;i<j;i++){
        k.push(a[i]);
    }
    for(int i=1;i<j;i++){
        cout<<k.top();
        k.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
