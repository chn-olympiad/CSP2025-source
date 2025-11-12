#include<bits/stdc++.h>
using namespace std;
struct aaa{
    string s1;
    string s2;
};
aaa s[200010],t[200010];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
    }
    for(int i=1;i<=q;i++){
        cin>>t[i].s1>>t[i].s2;
    }
    for(int i=1;i<=q;i++){
        if(t[i].s1.size()!=t[i].s2.size()){
            cout<<"0\n";
            continue;
        }
        int shuchu=0;
        for(int j=1;j<=n;j++){
            bool biaoji=true;
            int n_j=0;
            for(int k=0;k<t[i].s1.size();k++){
                if(t[i].s1[k]!=t[i].s2[k]&&n_j>=s[j].s1.size()){
                    biaoji=false;
                    break;
                }if(t[i].s1[k]!=t[i].s2[k]&&(t[i].s1[k]!=s[j].s1[n_j]||t[i].s2[k]!=s[j].s2[n_j])){
                    biaoji=false;
                    break;
                }else if(t[i].s1[k]!=t[i].s2[k]&&t[i].s1[k]==s[j].s1[n_j]&&t[i].s2[k]==s[j].s2[n_j]){
                    n_j++;
                }
            }
            if(biaoji) shuchu++;
        }
        cout<<shuchu<<"\n";
    }
    return 0;
}
/*
san xia  bei wei  li dao yuan
zi san xia qi bai li zhong  liang an lian shan  lve wu qve chu  
chong yan die zhang  yin tian bi ri  zi fei ting wu ye fen  bu jian xi yue  
zhi yu xia shui xiang ling  yan su zu jve  huo wang ming ji xuan  you shi zhao fa bai di  mu dao jiang ling  
qi jian qian er bai li  sui cheng ben yu feng  bu yi ji ye  
chun dong zhi shi  ze su tuan lv tan  hui qing dao ying  jve yan duo sheng guai bai  xvan qvan pu bu  fei shu qi jian  
qing rong jvn mao  liang duo qv wei  
mei zhi qing chu shuang dan  lin han jian su  chang you gao yvan chang xiao  zhu yin qi yi  kong gu chuan xiang  ai zhuan jiu jve  
gu yv zhe ge yve  ba dong san xia wu xia chang  yvan ming san sheng lei zhan chang  
*/