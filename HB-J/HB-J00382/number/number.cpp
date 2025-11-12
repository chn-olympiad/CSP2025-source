#include<bits/stdc++.h>
using namespace std;
string s;
long long j=0;
int a[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(long long i=0;i<=n-1;i++){
        if(s[i]>='a' && s[i]<='z'){}
        else {
            a[j]=s[i]-48;
            j++;
        }
    }
    sort(a,a+j);
    for(long long i=j-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
