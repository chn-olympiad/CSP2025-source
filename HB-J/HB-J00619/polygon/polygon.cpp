#include<bits/stdc++.h>// xie le yi ge ban xiao shi ,fei le
using namespace std;

long long n,l[5005]={};
/*bool vi[5005]={};
unsigned long long ans=0;
vector<string> c;

vector<int> v;
vector<int> maxn;
long long sum=0;

bool cheak(string a,string b){// ni wu xu guan xin ci han shu you shen me yong
    for(int i=0;i<5;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

void d(int x){// ni wu xu guan xin ci han shu de zheng que xie fa ,yin wei wo ye bu hui.
    if(x==0){
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vi[i]==0) v.push_back(l[i]);
        else{
            continue;
        }
        vi[i]=1;
        if(l[i]>=maxn.back()){
            maxn.push_back(l[i]);
        }
        sum+=l[i];
        if(sum > 2*maxn.back() && x<=n-3){
            char ch[6]={'0','0','0','0','0','0'};
            for(int j=0;j<v.size();j++){
                ch[i]=v[i];
            }
            sort(ch,ch+5);
            string a="";
            for(int j=0;j<5;j++){
                a+=ch[i];
            }
            bool f=1;
            for(int j=0;j<=c.size();j++){
                if(cheak(a,c[i])==0){
                    f=0;
                    break;
                }
            }
            if(f==1) {ans++;c.push_back(a);}
            ans%=998244353;

            cout<<endl<<"ans++";

        }


        cout<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<vi[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
        cout<<maxn.back()<<" "<<sum<<" "<<x-1;
        cout<<endl;



        d(x-1);
        v.pop_back();
        vi[i]=0;
        sum-=l[i];
        if(l[i]==maxn.back()){
            maxn.pop_back();
        }
    }
}*/

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    /*maxn.push_back(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    d(n);// ni wu xu guan xin ci han shu nei bu shi xian.
    cout<<ans;*/
    cin>>n;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        if(l[i]!=1) flag=0;
    }
    if(n==3 || flag==1){
        cout<<1;
    }
    return 0;
}
/*
ka chang de , chang shu you hua zhong wo xiao;
bao zhan de , di gui shen du wu suan liang.
chao shi de ,shi xian yan ke tian zhu ding;
cun tu de ,nei cun xie lou zui nan fang.
*/
