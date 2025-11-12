#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0<<'\n';
    }
    else{
        if(a[1]+a[2]>a[3]){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
}
//难度还行，大概红 橙 绿 蓝
//还是不能稳定场切绿
//我还是太菜了
//怎么还有一个小时！！！
//T3真调不出来了
//T4也就这样吧，4-5分？
//困了，想睡觉
//这系统的中文输入法这么难用
//我精神了，在检查一下T1T2吧，没问题
//还有半个小时了
//我饿了
//又困了睡会
//T4也就只能这么骗了
//10分钟拉
//下午还得来
//5分钟辣
//许愿280
//以查看freopen
//1分钟
//撤退
