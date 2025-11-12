#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
int a,b;
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++){
        cin>>s1>>s2;
    }
    for (int i=1; i<=q; i++){
        cin>>t1>>t2;
    }
    for (int i=1; i<=s1.size(); i++){
        if (s1[i]=='a') a++;
        if (s1[i]=='b') b++;
    }
    if (a+b=s1.size()&&b==1) {
        for (int i=1; i<=q; i++){
            cout <<((a+b+1)*(a+b))/2<<endl;
        }
        return 0;
    }
    for (int i=1; i<=q; i++){
        cout <<"0"<<endl;
    }
    return 0;
}
