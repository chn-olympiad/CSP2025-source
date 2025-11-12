#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=0;
    int k=s.size();
    int c=0;
    char a[1000000];
    for(int i=0;i<k;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i];
            b++;
            cout<<a[b];
        }
    }

    sort(a,a+b);

    for(int i=b-1;i>=0;i--){
        cout<<int(a[i])-48;
    }

}
