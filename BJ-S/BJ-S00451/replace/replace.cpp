#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s1[n],s2[n];
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string t1,t2;
        int sum=0;
        cin>>t1>>t2;
        for(int i=0;i<n;i++){
            for(int l=0;l<t1.size();l++){
                int r=0;
                if(t1[l]!=s1[i][l-r]){
                    r=l+1;
                }
                if(l-r==s1[i].size()-1){
                    string t=t1;
                    for(int ll=r;ll<=l;ll++){
                        t[ll]=s2[i][ll-r];
                    }
                    cout<<t<<" "<<s1[i]<<endl;
                    if(t==t2){
                        sum++;
                    }
                    r=l+1;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
