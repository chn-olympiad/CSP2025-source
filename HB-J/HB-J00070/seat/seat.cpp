#include<bits/stdc++.h>
using namespace std;
int n,m;
struct chengji{
    int score,id,ranking;
}a[101];
bool cmp1(chengji a,chengji b){
    return a.score>b.score;
}
bool cmp2(chengji a,chengji b){
    return a.id<b.id;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;++i){
        cin>>a[i].score;
        a[i].id=i;
    }
    //第一次排序：按分数大->小排序
    sort(a,a+n*m,cmp1);
    for(int i=0;i<n*m;++i){
        //将排名写到ranking中
        a[i].ranking=i;
    }
    //第二次排序：按id小->大排序
    sort(a,a+n*m,cmp2);
    //排名确定了，接下来就要确定位置了
    int r_ranking=a[0].ranking;
    //注意：周期是2*n
    int shang=r_ranking/n; //其实要确定列，除以n就行了
    int remain=r_ranking%(2*n);
    //注意：若remain>=n,则remain=2*n-1-remain
    if(remain>=n){
        remain=2*n-1-remain;
    }
    cout<<(shang+1)<<" "<<(remain+1)<<"\n"; //注意输出结果要+1
    return 0;
}
