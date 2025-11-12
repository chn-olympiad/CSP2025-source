#include<bits/stdc++.h>
using namespace std;

int n,k,temp_,res;
vector<int> OPK;

int xor_(int p1,int p2){
    string res,res1;
    int rax,num;
    rax=p1|p2;
    while(rax!=0){
        res+=rax%2+'0';
        rax/=2;
    }
    for(auto i:res){
        if(i=='0')  res1+='1';
        else  res1+='0';
    }
    for(auto i=res1.size();i>=0;i--){
        num+=(res1[i]-'0')*pow(2,res1.size()-i);
    }
    return num;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    OPK.push_back(0);
    for(int i=0;i<n;i++){
        cin>>temp_;
        OPK.push_back(temp_);
    }
    int l=1,r=1;
    for(;l<=OPK.size();){
        r=l;
        if(r==l && OPK[l]==k)  res++;
        else{
            int tepp=OPK[l];
            for(r++;r<=OPK.size();r++){
                tepp=xor_(tepp,OPK[r]);
                if(tepp==k){
                    res++;
                    l++;
                    break;
                }
            }
        }
        l++;
    }
    cout<<res;
}
