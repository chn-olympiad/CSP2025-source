#include<bits/stdc++.h>
using namespace std;
int read(){
    int n=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        n=(n<<3)+(n<<1)+(ch^48);
        ch=getchar();
    }
    return n*f;
}
const int N=2e5+5;
string a[N],b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n=read();
    int q=read();
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.size(),l2=s2.size();
        if(l1!=l2){
            cout<<0<<endl;
            continue;
        }

        cout<<n-l1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
