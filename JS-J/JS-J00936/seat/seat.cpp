#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
    return a>b;
}
int R;
int stu[10000];
int stu_num;
int sat;
int lie,hang;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    stu_num=n*m;
    for(int i=1;i<=stu_num;i++){
        cin>>stu[i];
        if(i==1){
            R=stu[i];
        }
    }
    sort(stu+1,stu+stu_num+1,cmp);
    for(int i=1;i<=stu_num;i++){
        if(stu[i]==R){
            sat=i;
            break;
        }
    }
    lie=sat/n+(sat%n?1:0);
    cout<<lie;
    hang=(sat%n+n-1)%n+1;
    if(lie%2==0){
        hang=n-hang+1;
    }
    cout<<" "<<hang;
    return 0;
}
