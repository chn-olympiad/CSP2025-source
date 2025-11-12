#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main(){
    string s;
    int i,j,b=0,c;
    freopen("\\Desktop\\cspj.zip\\down.zip\\number\\number.in","r",stdin);
    freopen("\\Desktop\\JS-J01053\\number.out","w",stdout);
    cin>>s;
    cout<<s;
    c=s.length();
    for(i=0;i<c;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a,a+c);
    for(i=b-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
