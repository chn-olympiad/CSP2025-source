#include <iostream>

using namespace std;

string s;
int a[10];
bool is=true;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]<'a'){
            int x=s[i]-'0';
            a[x]++;
        }
    }

    is=false;
    for(int i=9;i>=1;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
            is=true;
        }
    }

    if(is){
        for(int i=1;i<=a[0];i++)
            cout<<0;
    }
    else{
        cout<<0;
    }


    return 0;
}
