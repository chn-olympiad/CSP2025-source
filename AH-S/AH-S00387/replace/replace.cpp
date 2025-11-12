#include<bits/stdc++.h>
using namespace std;
struct node{
    string s1,s2;
}a[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
    while(q--){
        int sum=0;
        string s3,s4;
        cin>>s3>>s4;
        for(int i=1;i<=n;i++){
            string s=s3;
            if(s.find(a[i].s1)>s.size()+101110000) continue;
            int x=s.find(a[i].s1);
            for(int j=0;j<a[i].s1.size();j++){
                s[x+j]=a[i].s2[j];
            }
            if(s==s4) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
