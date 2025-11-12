#include<bits/stdc++.h>
using namespace std;
string s;
long long c,b;
long long a[1000010];
int main(){
    feopen("number.in","r",stdin);
    feopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    int n=l-1;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
               a[i]=s[i]-'0';
                c++;
        }
        else{
            b++;
        }
    }
    sort(a,a+l);
    for(int i=n;i>n-c;i--){
            cout<<a[i];
        }

    return 0;
}

