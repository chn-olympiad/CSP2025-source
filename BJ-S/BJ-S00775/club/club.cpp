#include<bits/stdc++.h>
using namespace std;
struct shetuanzhaoxin{
    int a;
    int b;
    int c;
};
shetuanzhaoxin s[100010];
int t,n,shuchu;
void sou(int a,int b,int c,int x,int jishu){
    if(a>n/2||b>n/2||c>n/2){
        return;
    }else if(x>n){
        shuchu=max(shuchu,jishu);
        return;
    }else{
        sou(a+1,b,c,x+1,jishu+s[x].a);
        sou(a,b+1,c,x+1,jishu+s[x].b);
        sou(a,b,c+1,x+1,jishu+s[x].c);
        return;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        shuchu=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        sou(0,0,0,1,0);
        cout<<shuchu<<"\n";
    }
    return 0;
}
/*
ye wang  tang  wang ji
dong gao bo mu wang  xi yi yu he yi  
shu shu jie qiu se  shan shan wei luo hui  
mu ren qu du fan  lie ma dai qin gui  
xiang gu wu xiang shi  chang ge huai cai wei  
*/
/*
huang he lou  tang  cui hao  
xi ren yi cheng hung he qu  ci di kong yu huang he lou  
huang he yi qu bu fu fan  bai yun qian zai kong you you  
qing chuan li li han yang shu  fang cao qi qi ying wu zhou  
ri mu xiang guan he chu shi  yan bo jiang shang shi ren chou  
*/