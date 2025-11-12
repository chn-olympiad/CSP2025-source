#include<bits/stdc++.h>
using namespace std;
struct people{
    int a,b,c;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int ttt=0;ttt<t;ttt++){
        people p[100010]={};
        int n,s=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
        }
        people a[50010],b[50010],c[50010];
        int fa=0,fb=0,fc=0,pa=0,pb=0,pc=0;
        for(int i=1;i<=n;i++){
            pa=0;
            pb=0;
            pc=0;
            //ps=s;
            //cout<<a[1];
            //cout<<"s"<<s<<endl;
            if((fa+2)>n/2){
                pa-=a[fa].a;
                pa+=p[i].a;
            }
            else{
                pa+=p[i].a;
            }


            if((fb+2)>n/2){
                pb-=b[fb].b;
                pb+=p[i].b;
            }
            else{
                pb+=p[i].b;
            }


            if((fc+2)>n/2){
                pc-=c[fc].c;
                pc+=p[i].c;
            }
            else{
                pc+=p[i].c;
            }
            //cout<<"pa:"<<pa<<"pb:"<<pb<<"pc:"<<pc<<endl;
            int maxp=max(pa,max(pb,pc));
            if(maxp==pa){
                if((fa+1)>n/2){
                    s-=a[fa].a;
                    s+=p[i].a;
                    people t=a[fa];
                    a[fa]=p[i];
                    p[i]=t;
                    i--;
                }
                else{
                    a[fa++]=p[i];
                    s+=p[i].a;
                }
            }
            else if(maxp==pb){
                if((fb+1)>n/2){
                    s-=b[fb].b;
                    s+=p[i].b;
                    people t=b[fb];
                    b[fb]=p[i];
                    p[i]=t;
                    i--;
                }
                else{
                    b[fb++]=p[i];
                    s+=p[i].b;
                }
            }
            else{
                if((fc+1)>n/2){
                    s-=c[fc].c;
                    s+=p[i].c;
                    people t=c[fc];
                    c[fc]=p[i];
                    p[i]=t;
                    i--;
                }
                else{
                    c[fc++]=p[i];
                    s+=p[i].c;
                }
            }
            //cout<<"fs"<<s<<endl;
        }
        cout<<s<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
