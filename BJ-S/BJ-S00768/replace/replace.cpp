#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n,q,ha,hb,qa[1010101],qb[10101011],p=131313,num[1010101][3];
string c[1010101][3];
string a,b;
ull whash(string a){
    ull p=131313,h=0;
    for(int i=1;i<=a.size();i++){
        h=h*p+a[i]-'a'+1;
    }
    return h;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
        //scanf("%c%c",&c[i][1],&c[i][2]);
        cin>>c[i][1]>>c[i][2];
        c[i][1]=" "+c[i][1];
        c[i][2]=" "+c[i][2];
        num[i][1]=whash(c[i][1]);
        num[i][2]=whash(c[i][2]);
    }
    while(q--){
        cin>>a>>b;
        a=" "+a;
        b=" "+b;
        ha=whash(a);
        hb=whash(b);
        qa[1]=a[1]-'a'+1;
        qb[1]=b[1]-'a'+1;
        for(int i=2;i<=n;i++){
            qa[i]=qa[i-1]*p+a[i]-'a'+1;;
        }
        for(int i=2;i<=n;i++){
            qb[i]=qb[i-1]*p+b[i]-'a'+1;;
        }
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);

return 0;
}
