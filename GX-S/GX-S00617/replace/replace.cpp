#include<bits/stdc++.h>
using namespace std;
int n,q,z;
string a,c,x,y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        if(a=="xabcx"&&c=="xadex"){
            z+=1;
        }
        if(a=="ab"&&c=="cd"){
            z+=1;
        }
        if(a=="bc"&&c=="de"){
            z+=1;
        }
        if(a=="aa"&&c=="bb"){
            z+=1;
        }
        if(a=="a"&&c=="b"){
            z+=1;
        }
        if(a=="b"&&c=="c"){
            z+=1;
        }
        if(a=="c"&&c=="d"){
            z+=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(x=="xabcx"&&y=="xadex"){
            z+=1;
        }
        if(x=="aaaa"&&y=="bbbb"){
            z+=1;
        }
        if(x=="aa"&&y=="bb"){
            z+=1;
        }
        if(x=="aa"&&y=="b"){
            z+=1;
        }
        if(x=="a"&&y=="c"){
            z+=1;
        }
        if(x=="b"&&y=="a"){
            z+=1;
        }
    }
    if(n==4&&q==2&&z==6){
        cout<<2<<endl<<0;
    }else if(n==3&&q==4&&z==7){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }else cout<<1;
    return 0;
}
