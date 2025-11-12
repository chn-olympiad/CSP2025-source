#include <iostream>
#include <algorithm>
using namespace std;

/*
答题思路：首先我们要对a进行降序排序，然后才能排座位
因为所有的ai互不相同，直接遍历就可以确定小R的排名
然后让我在草稿纸上算一下，i与座位的问题
*/
//n表示行数
int a[101];
int solveL(int pm,int n){

    if(pm%n==0) return pm/n;
    else return pm/n+1;
}

int solveH(int pm,int n,int L){
    bool great=(L%2==1);//1为1~n,0为n~1
    int place=(pm-1)%n+1;//这一列中的第几个？
    if(great){
        return place;
    }
    else{
        return n-place+1;
    }
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int seatnum=n*m;
    for(int i=1;i<=seatnum;i++){
        cin>>a[i];
    }
    int gradeR=a[1],paimingR=0;
    sort(a+1,a+seatnum+1,greater<int>());
    for(int i=1;i<=seatnum;i++){
        if(a[i]==gradeR){
            paimingR=i;
            break;
        }
    }
    int ans_L=solveL(paimingR,n);
    int ans_H=solveH(paimingR,n,ans_L);
    cout<<ans_L<<" "<<ans_H;
    return 0;
}

/*
终于写完了！似乎只有S组能上迷惑行为，但我不管了
就这样在OI的道路上前行
今夜也在径直地 寻找着这道题的AC路径
尽管这条道路可能已经一方通行
但是暴力加上模拟 一定能够通过样例 There You Will...
Be The One Be The One All Right!
不能对明天的CCF置之不理
Be The Light Be The Light All Right!
就从这里出发 继续下一道题
（编不下去了）
*/