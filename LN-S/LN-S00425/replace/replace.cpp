#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    string s1[211451],s2[211451];
    string t1[211451],t2[211451];
    for(int i=0;i<n;i++){
        cin>>s1[i]<<s2[i];
        cin>>t1[i]>>t2[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<s1.size();k++){
                for(int l=0;l<t1.size();l++){
                    if(s1[i][k]!=t1[j][l]){
                        break;
                    }
                }
            }
        }
    }
}
