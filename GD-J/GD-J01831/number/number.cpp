#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string a[10001];
    int n=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
        	n++;
            a[n]=s[i];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<int(a[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
