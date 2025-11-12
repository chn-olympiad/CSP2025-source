#include<bits/stdc++.h>
using namespace std;
int n,m,shuchu=0;
int c[600],pai[600],biaoji[600],he[600];
char s[600];
void sou(int x,int jishu){
    pai[jishu]=x;
    if(jishu==n){
        // cout<<"11111\n";
        // for(int i=1;i<=n;i++){
        //     cout<<pai[i]<<' ';
        // }
        // cout<<"\n";
        int weilq=0,lq=0;
        for(int i=1;i<=n;i++){
            if(weilq>=c[pai[i]]){
                weilq++;
                //cout<<"   33333\n";
            }else{
                if(s[i]=='0'){
                    weilq++;
                    //cout<<"   44444\n";
                }else{
                    lq++;
                    //cout<<"   22222\n";
                }
            }
            if(n-weilq<m) return;
        }
        if(lq>=m){
            shuchu++;
            shuchu%=998244353;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(!biaoji[i]){
                biaoji[i]=true;
                sou(i,jishu+1);
                biaoji[i]=false;
            }
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<600;i++){
        biaoji[i]=false;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        s[i]=x;
        he[i]=he[i-1];
        if(x=='0') he[i]++;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        biaoji[i]=true;
        sou(i,1);
        biaoji[i]=false;
    }
    cout<<shuchu;
    return 0;
}
/*
yv zhu yvan si shu  nan chao liang  wu jvn
feng yan jv jing  tian shan gong se  cong liu piao dan  ren yi dong xi  
zi fu yang zhi tong lu yi bai xv li  qi shan yi shui  tian xia du jve  
shui jie piao bi  qian zhang jian di  you yu xi shi  zhi shi wu ai  ji tuan shen jian  meng lang ruo ben  
jia an gao shan  jie sheng han shu  fu shi jing shang  hu xiang xuan miao  
zheng gao zhi zhi  qian bai cheng feng  quan shui ji shi  ling ling zuo xiang  hao niao xiang ming  ying ying cheng yun  
chan ze qian zhuan bu qiong  yvan ze bai jiao wu jve  
yvan fei li tian zhe  wang feng xi xin  jing lun shi wu zhe  kui gu wang fan  
heng ke shang bi  zai zhou you hun  shu tiao jiao ying  you shi jian ri  
*/
//wo yao shang mi huo xing wei da shang !!!