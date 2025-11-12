#include<bits/stdc++.h>
#define ll long long
using namespace std;

string a;
ll b,c[11];

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    getline(cin,a);
    b=a.size();
    for(ll i=0;i<b;i++)if(a[i]>='0'&&a[i]<='9')c[a[i]-'0']++;
    for(int i=9;i>=0;i--)while(c[i]>0){
        c[i]--;
        cout<<i;
    }
    cout<<endl;

    return 0;

}
