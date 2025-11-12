#include<bits/stdc++.h>
using namespace std;
int tong[5000001]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int a=0,b=0;
        for(int j=0;i<s1.length();i++) if(s1[i]=='b') a=j;
        for(int j=0;i<s2.length();i++) if(s2[i]=='b') b=j;
        int c;
        if(a>b){
            c=a-b;
        }else c=b-a;
        tong[c]++;
    }
    for(int i=0;i<q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int a=0,b=0;
        for(int j=0;i<s1.length();i++) if(s1[i]=='b') a=j;
        for(int j=0;i<s2.length();i++) if(s2[i]=='b') b=j;
        int c;
		a>b?c=a-b:c=b-a;
        cout<<tong[c]<<"\n";
    }
    return 0;
}
