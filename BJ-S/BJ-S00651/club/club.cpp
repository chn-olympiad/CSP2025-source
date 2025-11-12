#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    int anss=0;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<int> key;
        vector<int>key1;
        vector<int>key2;
        int a;
        cin>>a;
        key.resize(a+1);
        key1.resize(a+1);
        key2.resize(a+1);
        int ans[1000][1000];
        for(int j=0;j<a;j++){
            for(int k=0;k<3;k++){
                cin>>ans[j][k];
            }
        }
        for(int j=0;j<a;j++){
            key[j]=ans[j][0];
            key1[j]=ans[j][1];
            key2[j]=ans[j][2];
        }
        sort(key.begin(),key.end());
        sort(key1.begin(),key1.end());
        sort(key2.begin(),key2.end());
        int b=a/2;
        for(int j=a-1;j>b;j--){
            anss+=key[j];
            anss+=key1[j];
            anss+=key2[j];
        }
        cout<<anss<<endl;
        anss=0;
    }
    return 0;
}