#include <bits/stdc++.h>
using namespace std;
int n,af,la,lb,lc,sb,ssb,sbb;
struct pdf{
    int a,b,c;
}s[100001];
int a[100001];
bool cmp(int hhgdfu,int ftcdghgfy){
    return hhgdfu>ftcdghgfy;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    while(n--){

        cin>>af;
        for(int i=0;i<af;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            a[i]=s[i].a;
            if(s[i].b!=0||s[i].c!=0){
                ssb=1;
            }
                if(s[i].c!=0){
                    sbb=1;
                }
        }
        if(ssb==0){
            sort(a,a+af,cmp);
            int y;
            for(int i=0;i<af/2;i++){
                y+=a[i];
            }
            cout<<y;
        }
        else{for(int j=0;j<af;j++){
            if(max(s[j].a,max(s[j].b,s[j].c))==s[j].a){
                if(la+1<=af/2){
                    sb+=s[j].a;
                la++;

                }
            }
            if(max(s[j].a,max(s[j].b,s[j].c))==s[j].b){
                if(lb+1<=af/2){
                    sb+=s[j].b;
                    lb++;
                }
            }
            if(max(s[j].a,max(s[j].b,s[j].c))==s[j].c){
                if(lc+1<=af/2){
                    sb+=s[j].c;
                    lc++;
                }
            }
        }
        cout<<sb;
        cout<<endl;
        sb=0;
        la=0;
        lb=0;
        lc=0;
    }}
    return 0;
}

