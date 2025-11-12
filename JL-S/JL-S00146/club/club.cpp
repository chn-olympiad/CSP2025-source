#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t,n,i,j,cnta,cntb,cntc;
struct agreement{
    long long a,b,c,sa,sb,sc;
}aa[maxn],bb[maxn],cc[maxn],stud[maxn];
bool cmp1(agreement x,agreement y){
    return (x.a>y.a);
}
bool cmp2(agreement x,agreement y){
    return (x.b>y.b);
}
bool cmp3(agreement x,agreement y){
    return (x.c>y.c);
}
void check(agreement x,agreement y,char ch,int pos){
    switch(ch){
        case 'a':{
            if(y.b-y.a+x.a>=0&&cntb+1<=n/2){
                cnta--;
                bb[cntb]=aa[cnta];
                aa[cnta]=x;
                cnta++;
                cntb++;
            }
            else if(y.c-y.a+x.a>=0&&cntc+1<=n/2){
                cnta--;
                cc[cntc]=aa[cnta];
                aa[cnta]=x;
                cnta++;
                cntc++;
            }
            check(stud[pos-1],x,'a',pos-1);
            break;
        }
        case 'b':{
            if(y.a-y.b+x.b>=0&&cnta+1<=n/2){
                cntb--;
                aa[cnta]=bb[cntb];
                bb[cntb]=x;
                cntb++;
                cnta++;
            }
            else if(y.c-y.b+x.b>=0&&cntc+1<=n/2){
                cntb--;
                cc[cntc]=bb[cntb];
                bb[cntb]=x;
                cntb++;
                cntc++;
            }
            check(stud[pos-1],x,'b',pos-1);
            break;
        }
        case 'c':{
            if(y.a-y.c+x.c>=0&&cnta+1<=n/2){
                cntc--;
                aa[cnta]=cc[cntc];
                cc[cntc]=x;
                cntc++;
                cnta++;
            }
            else if(y.b-y.c+x.c>=0&&cntb+1<=n/2){
                cntb--;
                bb[cntb]=cc[cntc];
                cc[cntc]=x;
                cntc++;
                cntb++;
            }
            check(stud[pos-1],x,'c',pos-1);
            break;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        int sum=0;
        cnta=0;
        cntb=0;
        cntc=0;
        for(j=0;i<n;j++){
            cin>>stud[j].a>>stud[j].b>>stud[j].c;
        }
        sort(stud,stud+n,cmp1);
        for(j=0;i<n;j++){
            stud[j].sa=stud[j].a;
        }
        sort(stud,stud+n,cmp2);
        for(j=0;i<n;j++){
            stud[j].sb=stud[j].b;
        }
        sort(stud,stud+n,cmp3);
        for(j=0;i<n;j++){
            stud[j].sc=stud[j].c;
        }
        if(min(min(stud[0].sa,stud[0].sb),stud[0].sc)==stud[0].sa){
            aa[0]=stud[0];
            cnta++;
        }
        else if(min(min(stud[0].sa,stud[0].sb),stud[0].sc)==stud[0].sb){
            bb[0]=stud[0];
            cntb++;
        }
        else if(min(min(stud[0].sa,stud[0].sb),stud[0].sc)==stud[0].sc){
            cc[0]=stud[0];
            cntc++;
        }
        for(j=1;j<n;j++){
            if(min(min(stud[j].sa,stud[j].sb),stud[j].sc)==stud[j].sa){
                if(cnta+1>n/2){
                    check(stud[j],stud[j-1],'a',j);
                }
                else{
                    aa[cnta]=stud[j];
                    cnta++;
                }
            }
            else if(min(min(stud[j].sa,stud[j].sb),stud[j].sc)==stud[j].sb){
                if(cntb+1>n/2){
                    check(stud[j],stud[j-1],'b',j);
                }
                else{
                    bb[cntb]=stud[j];
                    cntb++;
                }
            }
            else if(min(min(stud[j].sa,stud[j].sb),stud[j].sc)==stud[j].sc){
                if(cntc+1>n/2){
                    check(stud[j],stud[j-1],'c',j);
                }
                else{
                    cc[cntc]=stud[j];
                    cntc++;
                }
            }
        }
        for(j=0;j<cnta;j++){
            sum+=aa[i].a;
        }
        for(j=0;j<cntb;j++){
            sum+=bb[i].b;
        }
        for(j=0;j<cnta;j++){
            sum+=cc[i].c;
        }
        cout<<sum;
    }
    return 0;
}
