#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int s1 = s.length();
    int b[100000],n=0;
    int l=0;
    for(int i=0;i<s1;i++){
        l++;
        for(int p=0;p<10;p++){
            if( p+48 == int(s[i])){
                    b[l] = p;
                    n++;
                    
            }
            
        }
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<b[i];
    }
    return 0;
}