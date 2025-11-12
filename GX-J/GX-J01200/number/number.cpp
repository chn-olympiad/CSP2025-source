include<bit/stdc++.h>
using namespace std;
main{
    int n[100005];
    string s;
    freopen("number.in","r","stdin");
    cin>>s;
    for(int i=0;i<=leng(s);i++){
        if(s[i]<=9){
            n[i]=s[i]
        }
    }
    sort(0,n+1);
    
    for(int i=0;i<=leng(s);i++){
            cout<<n[i];
    }
    freopen("number.out","w","stdout");
    return 0;
}
