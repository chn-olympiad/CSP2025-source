#include<bits/stdc++.h>
using namespace std;
int n,a[100],ans;
void A3()
{
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++)
    if(a[a1]+a[a2]+a[a3]>max({a[a1],a[a2],a[a3]})*2) ans=(ans+1)%998244353;
}
void A4()
{
    A3();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    if(a[a1]+a[a2]+a[a3]+a[a4]>max({a[a1],a[a2],a[a3],a[a4]})*2) ans=(ans+1)%998244353;
}
void A5()
{
    A4();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]>max({a[a1],a[a2],a[a3],a[a4],a[a5]})*2) ans=(ans+1)%998244353;
}
void A6()
{
    A5();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6]})*2) ans=(ans+1)%998244353;
}
void A7()
{
    A6();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7]})*2) ans=(ans+1)%998244353;
}
void A8()
{
    A7();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8]})*2) ans=(ans+1)%998244353;
}
void A9()
{
    A8();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9]})*2) ans=(ans+1)%998244353;
}
void A10()
{
    A9();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10]})*2) ans=(ans+1)%998244353;
}
void A11()
{
    A10();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b]})*2) ans=(ans+1)%998244353;
}
void A12()
{
    A11();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c]})*2) ans=(ans+1)%998244353;
}
void A13()
{
    A12();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d]})*2) ans=(ans+1)%998244353;
}
void A14()
{
    A13();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e]})*2) ans=(ans+1)%998244353;
}
void A15()
{
    A14();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f]})*2) ans=(ans+1)%998244353;
}
void A16()
{
    A15();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++) for(int g=f+1;g<=n;g++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f],a[g]})*2) ans=(ans+1)%998244353;
}
void A17()
{
    A16();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++) for(int g=f+1;g<=n;g++)
    for(int h=g+1;h<=n;h++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f],a[g],a[h]})*2) ans=(ans+1)%998244353;
}
void A18()
{
    A17();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++) for(int g=f+1;g<=n;g++)
    for(int h=g+1;h<=n;h++) for(int i=h+1;i<=n;i++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f],a[g],a[h],a[i]})*2) ans=(ans+1)%998244353;
}
void A19()
{
    A18();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++) for(int g=f+1;g<=n;g++)
    for(int h=g+1;h<=n;h++) for(int i=h+1;i<=n;i++) for(int j=i+1;j<=n;j++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f],a[g],a[h],a[i],a[j]})*2)
        ans=(ans+1)%998244353;
}
void A20()
{
    A19();
    for(int a1=1;a1<=n;a1++) for(int a2=a1+1;a2<=n;a2++) for(int a3=a2+1;a3<=n;a3++) for(int a4=a3+1;a4<=n;a4++)
    for(int a5=a4+1;a5<=n;a5++) for(int a6=a5+1;a6<=n;a6++) for(int a7=a6+1;a7<=n;a7++) for(int a8=a7+1;a8<=n;a8++)
    for(int a9=a8+1;a9<=n;a9++) for(int a10=a9+1;a10<=n;a10++) for(int b=a10+1;b<=n;b++) for(int c=b+1;c<=n;c++)
    for(int d=c+1;d<=n;d++) for(int e=d+1;e<=n;e++) for(int f=e+1;f<=n;f++) for(int g=f+1;g<=n;g++)
    for(int h=g+1;h<=n;h++) for(int i=h+1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++)
    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]>max({a[a1],a[a2],a[a3],a[a4],a[a5],a[a6],a[a7],a[a8],a[a9],a[a10],a[b],a[c],a[d],a[e],a[f],a[g],a[h],a[i],a[j],a[k]})*2)
        ans=(ans+1)%998244353;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3) A3();
    if(n==4) A4();
    if(n==5) A5();
    if(n==6) A6();
    if(n==7) A7();
    if(n==8) A8();
    if(n==9) A9();
    if(n==10) A10();
    if(n==11) A11();
    if(n==12) A12();
    if(n==13) A13();
    if(n==14) A14();
    if(n==15) A15();
    if(n==16) A16();
    if(n==17) A17();
    if(n==18) A18();
    if(n==19) A19();
    if(n==20) A20();
    cout<<ans;
    return 0;
}
