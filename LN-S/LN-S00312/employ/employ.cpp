#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int Maxn=20005;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,q,l,r;
    int ans=0;
    cin>>n>>q;
    string s[Maxn]={},s2[Maxn]={};
    string t1,t2;
    vector<int> kmp1[Maxn]={};
    //vector<int> kmp2[1005]={}
    for(int i=0;i<n;i++){
        cin>>s[i]>>s2[i];
        kmp1[i].push_back(0);
        //kmp2[i].push_back(0);
        for(int j=1;j<s[i].length();j++){
            if(s[i]==s[kmp1[i][j-1]])kmp1[i].push_back(kmp1[i][j-1]+1);
            else kmp1[i].push_back(0);
        }
        /*for(int j=1;j<s2[i].length();j++){
            if(s2[i]==s2[kmp2[i][j-1]])kmp2[i].push_back(kmp2[i][j-1]+1);
            else kmp2[i].push_back(0);
        }*/
    }
    for(int i=0;i<q;i++){
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<"0\n";
            continue;
        }
        int l=-1;r=t1.length();
        for(int m=0;m<t1.length();m++){
            if(t1[m]!=t2[m])break;
            l=m;
        }
        for(int m=t1.length()-1;m>=0;m--){
            if(t1[m]!=t2[m])break;
            r=m;
        }
        ans=0;
        //cout<<l<<" "<<r<<endl;
        for(int i=0;i<n;i++){
            int p=0,p2=max((int)(l-s[i].length()),0);
            while(p<t1.length()){
                //cout<<"check"<<i<<" "<<p<<" "<<p2<<endl;
                if(t1[p]==s[i][p2]){
                    p++;
                    p2++;
                }
                else{
                    //cout<<"else!"<<endl;
                    p2=kmp1[i][p2];
                    if(p2==0)p++;
                }
                if(p2>=s[i].length()){
                    //cout<<"range"<<p-p2<<" "<<p-1<<endl;
                    if(p-p2<=l+1&&p>=r){
                        //cout<<"in!!!!!!"<<endl;
                        bool f=0;
                        for(int k=p-p2;k<p;k++){
                            if(t2[k]!=s2[i][k-p+p2]){
                                f=1;
                                break;
                            }
                        }
                        if(!f){
                            ans++;
                            //cout<<"correct"<<endl;
                        }
                    }
                    p2=kmp1[i][s[i].length()-1];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
