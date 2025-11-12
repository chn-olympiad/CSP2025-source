#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int len=s.size();
    int cnt=0;
    char a[len];
    for(int i=0;i<len;i++){
        if(s[i]=='0' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
            a[cnt]=s[i];
            cnt++;
        }
    }

    for(int i=0;i<=cnt;i++){
        cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
