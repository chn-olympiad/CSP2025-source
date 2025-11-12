#include<bits/stdc++.h>
using namespace std;
string s;
char a[1111111];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c]=s[i];
            c++;
        }
    }
    for(int i=0;i<c;i++){
        for(int j=i;j<c;j++){
            if(a[j]>a[i])swap(a[j],a[i]);
        }
    }
    cout<<a<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
