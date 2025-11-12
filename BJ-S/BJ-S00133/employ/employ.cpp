#include<iostream>
#include<algorithm>
using namespace std;
const int inf=998244353;
long n,m,s[555],c[555],a[555],cnt,sum,p,ans,cn[555],sheng;
bool cmp(long x,long y)
{
    return x<y;
}
long Pow(long a)
{
    if(a==1) return 1;
    if(a==2) return 2;
    if(a==3) return 6;
    if(a==4) return 24;
    if(a==5) return 120;
    if(a==6) return 720;
    if(a==7) return 5040;
    if(a==8) return 40320;
    if(a==9) return 362880;
    if(a==10) return 3628800;
    if(a==11) return 39916800;
    if(a==12) return 479001600;
    if(a==13) return 237554682;
    if(a==14) return 331032489;
    if(a==15) return 972509923;
    if(a==16) return 586493473;
    if(a==17) return 986189864;
    if(a==18) return 781263551;
    if(a==19) return 868586527;
    if(a==20) return 401576539;
    if(a==21) return 447152495;
    if(a==22) return 853155713;
    if(a==23) return 655938692;
    if(a==24) return 768863313;
    if(a==25) return 254940118;
    if(a==26) return 638976950;
    if(a==27) return 282223649;
    if(a==28) return 914551701;
    if(a==29) return 567646151;
    if(a==30) return 59230529;
    if(a==31) return 837902046;
    if(a==32) return 858512294;
    if(a==33) return 380063818;
    if(a==34) return 943237576;
    if(a==35) return 71251511;
    if(a==36) return 568565690;
    if(a==37) return 73799117;
    if(a==38) return 807877740;
    if(a==39) return 561656917;
    if(a==40) return 504900914;
    if(a==41) return 736050414;
    if(a==42) return 966786798;
    if(a==43) return 643813841;
    if(a==44) return 376967120;
    if(a==45) return 991610752;
    if(a==46) return 693098707;
    if(a==47) return 631819933;
    if(a==48) return 380026194;
    if(a==49) return 652885152;
    if(a==50) return 700438304;
    if(a==51) return 783801149;
    if(a==52) return 827885628;
    if(a==53) return 953431105;
    if(a==54) return 574817667;
    if(a==55) return 669396742;
    if(a==56) return 551176491;
    if(a==57) return 471485044;
    if(a==58) return 393535021;
    if(a==59) return 258946120;
    if(a==60) return 563101905;
    if(a==61) return 408908203;
    if(a==62) return 396199761;
    if(a==63) return 4476118;
    if(a==64) return 286471552;
    if(a==65) return 652252526;
    if(a==66) return 124159537;
    if(a==67) return 332734155;
    if(a==68) return 664546774;
    if(a==69) return 932731521;
    if(a==70) return 405323525;
    if(a==71) return 827128391;
    if(a==72) return 656827325;
    if(a==73) return 32665781;
    if(a==74) return 420779088;
    if(a==75) return 612856657;
    if(a==76) return 657865694;
    if(a==77) return 743440788;
    if(a==78) return 90208990;
    if(a==79) return 138799739;
    if(a==80) return 123291237;
    if(a==81) return 4146667;
    if(a==82) return 340026694;
    if(a==83) return 271373718;
    if(a==84) return 834016546;
    if(a==85) return 16057347;
    if(a==86) return 382687489;
    if(a==87) return 351747894;
    if(a==88) return 8239729;
    if(a==89) return 733335881;
    if(a==90) return 116101992;
    if(a==91) return 582837742;
    if(a==92) return 714121555;
    if(a==93) return 529177317;
    if(a==94) return 828694501;
    if(a==95) return 862918061;
    if(a==96) return 984096910;
    if(a==97) return 624186735;
    if(a==98) return 277394497;
    if(a==99) return 509457672;
    if(a==100) return 35305197;
    long base=35305197;
    for(long z=101;z<=a;z++)
    {
        base=(base*z)%inf;
    }
    return base;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==0)
            cnt++;
        a[i]=cnt;
    }
    for(long i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+n+1,cmp);
    for(long i=1;i<=n;i++)
    {
        if(a[i]>=c[i])
        {
            for(long j=i+1;j<=n;j++)
            {
                a[j]++;
            }
        }
        cn[i]=c[i]-a[i];
    }
    sheng=sum-m+1;
    for(long i=1;i<=n;i++)
    {

        if(cn[i] && sheng)
        {
            ans=(ans+Pow(i))%inf;
            sheng--;
        }
    }
    cout<<ans%inf;
    return 0;
}
