#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
struct Node{
    int a,b,c,sum,maxx;
    int id;
    bool f=false;
};
// bool cmp(const Node &x,const Node &y)
// {
//     if(x.a!=y.a) return x.a>y.a;
//     else if(x.b!= y.b) return x.b>y.b;
//     else return x.c>y.c;
// }
// bool cmp2(const Node &x,const Node &y)
// {
//     if(x.b!=y.b) return x.b>y.b;
//     else if(x.a!= y.a) return x.a>y.a;
//     else return x.c>y.c;
// }
// bool cmp3(const Node &x,const Node &y)
// {
//    if(x.c!=y.c) return x.c>y.c;
//    else if(x.a!=y.a) return x.a>y.a;
//    else return x.c>y.c;
// }
Node e[N];
// int ansa,ansb,ansc;
// int ansa1,ansa2,ansb1,ansb2,ansc1,ansc2;
// int cnta,cntb,cntc;
// void clear()
// {
//     for(int i=1;i<=n;i++) e[i].f=false;
//     cnta=0;
//     cntb=0;
//     cntc=0;
//     return ;
// }
// void deal1_1()
// {
//     clear();
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansa1+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansa1+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansa1+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa1+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa1+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa1+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa1+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal1_2()
// {
//     clear();
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansa2+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansa2+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     sort(e+1,e+n+1,cmp2);
    
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansa2+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
    
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa2+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa2+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa2+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa2+=e[i].c;e[i].f=true;    cout<<"ansa1: "<<ansa1;

//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa2+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa2+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal1()
// {
//     deal1_1();
//     deal1_2();
//     ansa=max(ansa1,ansa2);
//     return ;
// }
// void deal2_1()
// {
//     clear();
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansb1+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansb1+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansb1+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansb1+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansb1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansb1+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansb1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansb1+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansb1+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal2_2()
// {
//     clear();
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansb2+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansb2+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansb2+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
    
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansb2+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansb2+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansb2+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansb2+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansb2+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansb2+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal2()
// {
//     deal2_1();
//     cout<<"ansb1: "<<ansb1;
//     deal2_2();
//     cout<<" ansb2: "<<ansb2<<'\n';
//     ansb=max(ansb1,ansb2);
//     return ;
// }
// void deal3_1()
// {
//     clear();
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansc1+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansc1+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansc1+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansc1+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansc1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansxe[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansc1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansc1+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansc1+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal3_2()
// {
//     clear();
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansc2+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansc2+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansc2+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansc2+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansc2+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansc2+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansc2+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansc2+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansc2+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void deal3()
// {
//     deal3_1();
//     deal3_2();
//     ansc=max(ansc1,ansc2);
//     return ;
// }
// void deal()
// {
//     clear();
//     sort(e+1,e+n+1,cmp);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==1 and !e[i].f)
//         {
//             ansa1+=e[i].a;
//             e[i].f=true;
//             cnta++;
//         }
//     }
//     sort(e+1,e+n+1,cmp2);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==2 and !e[i].f)
//         {
//             ansa1+=e[i].b;
//             e[i].f=true;
//             cntb++;
//         }
//     }
//     sort(e+1,e+n+1,cmp3);
//     for(int i=1;i<=n/2;i++)
//     {
//         if(e[i].id==3 and !e[i].f)
//         {
//             ansa1+=e[i].c;
//             e[i].f=true;
//             cntc++;
//         }
//     }
//     if(cnta>n/2)
//     {
//         int disa=cnta-n/2;
//         int disb=n/2-cntb;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].c)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa1+=e[i].b;e[i].f=true;
//             }
//             if(max(e[i].b,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntb>n/2)
//     {
//         int disb=cntb-n/2;
//         int disa=n/2-cnta;
//         int disc=n/2-cntc;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].a,e[i].c)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa1+=e[i].a;e[i].f=true;
//             }
//             if(max(e[i].a,e[i].c)==e[i].c and !e[i].f and e[i].id==3 and cntc<=n/2)
//             {
//                 ansa1+=e[i].c;e[i].f=true;
//             }
//         }
//     }
//     else if(cntc> n/2)
//     {
//         int disc=cntc-n/2;
//         int disb=n/2-cntb;
//         int disa=n/2-cnta;
//         for(int i=1;i<=n;i++)
//         {
//             if(max(e[i].b,e[i].a)==e[i].a and !e[i].f and e[i].id==1 and cnta<=n/2)
//             {
//                 ansa1+=e[i].a;e[i].f=true;
//             }
//             else if(max(e[i].b,e[i].a)==e[i].b and !e[i].f and e[i].id==2 and cntb<=n/2)
//             {
//                 ansa1+=e[i].b;e[i].f=true;
//             }
//         }
//     }
// }
// void clear_all()
// {
//     for(int i=1;i<=n;i++)
//     {
//         e[i].a=e[i].b=e[i].c=e[i].sum=e[i].maxx=e[i].id=e[i].f=0;
//     }
//     ansa1=ansa2=ansb1=ansb2=ansc1=ansc2=0;
//     clear();
// }

int cnt,tmp;
bool cmp(int x,int y){return x>y;}
int b[N];
void clear()
{
    memset(e,0,sizeof(e));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cnt=tmp=0;
    return ;
}
void solve1()
{
    for(int i=1;i<=n;i++) a[i]=e[i].a;
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n/2;i++) ans+=a[i];cout<<ans<<'\n';
}
// void solve2()
// {
//     sort(e+1,e+n+1,cmp2);int ans=0;
//     for(int i=1;i<=n/2;i++)
//     {
//         ans+=e[i].a;
//         e[i].f=true;
//     }
//     cout<<max(ans1,ans)<<'\n';
// }
void solve2()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=max({e[i].a,e[i].b,e[i].c});
    }
    cout<<ans<<'\n';
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i].a>>e[i].b>>e[i].c;
        if(e[i].b==0) cnt++;
        if(e[i].c==0) tmp++;
    }
    if(cnt==n and tmp==n)solve1();
    else solve2();
    clear();
}
int main()
{
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
