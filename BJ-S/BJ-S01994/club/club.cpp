#include <bits/stdc++.h>
using namespace std;
struct stu{
    int a,b,c,maxx,she;
    int ab,ba,ac,ca,bc,cb;
}s[100005];
int t,n,a[3][100005]={};
int av=0,bv=0,cv=0;
int as=0,bs=0,cs=0;
int abm[100005]={},acm[100005]={},bcm[100005]={},bam[100005]={},cam[100005]={},cbm[100005]={};
int cmpab(int x,int y){
    if(s[x].ab<0) return 0;
    if(s[y].ab<0) return 1;
    return s[x].ab<=s[y].ab;
}
int cmpba(int x,int y){
    if(s[x].ba<0) return 0;
    if(s[y].ba<0) return 1;
    return s[x].ba<=s[y].ba;
}
void check(){
    if(av>n/2){
        av--;
        bv++;
        s[abm[1]].she = 2;
        bam[bv] = abm[1];
        s[abm[1]].ab = -1;
        sort(abm+1,abm+av+1,cmpab);
        sort(bam+1,bam+bv+1,cmpba);
        check();
    }
    if(bv>n/2){
        av++;
        bv--;
        s[bam[1]].she = 1;
        abm[av] = bam[1];
        s[bam[1]].ba = -1;
        sort(abm+1,abm+av+1,cmpab);
        sort(bam+1,bam+bv+1,cmpba);
        check();
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++){
        cin>>n;
        for(int j = 1;j <= n;j++){
            cin>>s[j].a>>s[j].b>>s[j].c;
            s[j].ab = s[j].a-s[j].b;
            s[j].ba = s[j].b-s[j].a;
            s[j].ac = s[j].a-s[j].c;
            s[j].ca = s[j].c-s[j].a;
            s[j].bc = s[j].b-s[j].c;
            s[j].cb = s[j].c-s[j].b;
            s[j].maxx = max(max(s[j].a,s[j].b),s[j].c);
            if(s[j].maxx==s[j].a){
                s[j].she = 1;
                av++;
                abm[av] = j;
                sort(abm+1,abm+av+1,cmpab);
                check();
            }
            else if(s[j].maxx==s[j].b){
                s[j].she = 2;
                bv++;
                bam[bv] = j;
                sort(abm+1,abm+av+1,cmpab);
                check();
            }
        }
        for(int j = 1;j <= n;j++){
            if(s[j].she==1) as += s[j].a;
            if(s[j].she==2) bs += s[j].b;
        }
        cout<<as+bs<<endl;
        av = 0;
        bv = 0;
        as = 0;
        bs = 0;
    }
}
