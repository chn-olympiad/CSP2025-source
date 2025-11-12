#include<bits/stdc++.h>
using namespace std;
int anum[114514191];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a,b;
    cin>>a>>b;
    if(a^b==0)
        cout<<1;
    else if(a^b!=0)
        cout<<0;
    else
    cout<<2;
    return 0;
}
/*hai zi men wo yao wan dan le yi shi ying ming zuo bu chu lai di san ti
9:43 wo jue de shi sou suo , wo zuo guo huo shao chi bi gan jue he zhe ti hao xiang
dan shi wo wang le!!!
qu jian dp? wo wang le
mei shi j sai guo le jiu xing guan ta ji deng jiang
9:55 bao li dou xie bu chu lai de jiu shu gan
nan dao shi dp?
bu xing le da di si ti
Eggy_Hwang is my name
forgotten is my game!
*/
