#include<bits/stdc++.h>
    using namespace std;
    string a[200010],b[200010];
    int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    }
    string s1,s2;
    while(q--){
    cin>>s1>>s2;
    int s=0;
    for(int i=1;i<=n;i++){
    string s3=s1;
    if(s3.find(a[i])!=string::npos){
    int p=s3.find(a[i]);
    s3.erase(p,a[i].size());
    s3.insert(p,b[i]);
    if(s3==s2)s++;
    }
    }
    cout<<s<<endl;
    }
    return 0;
    }
