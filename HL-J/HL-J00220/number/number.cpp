#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
小R 正在学习字符串处理。小X 给了小R 一个字符串s，其中s 仅包含小写英文
字母及数字，且包. 含. 至. 少. 一. 个. 1 ∼ 9 中. 的. 数. 字. 。小 X 希望小 R 使用 s 中的任. 意. 多. 个. 数
字，按任. 意. 顺. 序. 拼成一个正整数。注. 意. ：小. R 可. 以. 选. 择. s 中. 相. 同. 的. 数. 字. ，但. 每. 个. 数. 字.
只. 能. 使. 用. 一. 次. 。例如，若 s 为 1a01b，则小 R 可以同时选择第 1, 3, 4 个字符，分别为
1, 0, 1，拼成正整数101 或110；但小R 不能拼成正整数111，因为s 仅包含两个数字1。
小R 想知道，在他所有能拼成的正整数中，最大的是多少。你需要帮助小R 求出
他能拼成的正整数的最大值。
*/

bool is_digit(char num){
    if(num=='1'||num=='2'||num=='3'||num=='4'||num=='5'||num=='6'||
       num=='7'||num=='8'||num=='9'||num=='0'){
        return true;
    }
    return false;
}
ll cti(char c){
    switch(c){
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}
vector<ll> bubble(vector<ll> vec,ll length){
    vec.resize(length);
    for(ll i=0;i<length;i++){
        for(ll j=i+1;j<length;j++){
            ll tmp=0;
            if(vec[j]<vec[i]){
                tmp=vec[i];
                vec[i]=vec[j];
                vec[j]=tmp;
            }
        }
    }

    return vec;
}

string str;
int main(){
    freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);

    cin>>str;
    ll len=str.size();
    ll lennum=0;
    long long ans=0;
    vector<ll> nums_cu;
    //cout<<len<<endl;

    for(ll i=0;i<len;i++){
        char tc=str[i];
        ll temp;
        //cout<<str[i]<<' ';
        if(is_digit(tc)){
            lennum+=1;
            nums_cu.resize(lennum);
            nums_cu.insert(nums_cu.begin(),cti(tc));//遍历时要用倒序遍历，从下标end-1开始
        }
    }

    //处理数据，组合数字
    //for(int n=0;n<nums_cu.size();n++){
    //    cout<<nums_cu[n]<<' ';
    //}

    ll ncu_len=nums_cu.size()-1;

    nums_cu=bubble(nums_cu,ncu_len);

    //for(int i=0;i<ncu_len;i++){
    //    cout<<nums_cu[i]<<' ';
    //}

    //升序排列向量，组合每一个数到ans中
    for(ll i=0;i<ncu_len;i++){
        ll j=1;
            for(ll n=0;n<i;n++){
                j*=10;
            }
        ans+=nums_cu[i]*j;
    }

    cout<<ans;

    return 0;
}
