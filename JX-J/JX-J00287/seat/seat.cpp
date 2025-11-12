#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int stu[505];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
        cin>>stu[i];
    }
    int xr = stu[1];
    int sum = n*m,cnt = 0;
    sort(stu+1,stu+sum+1,cmp);
    for(int i = 1;i<=sum;i++){
        if(stu[i] == xr){
            cnt = i;
            break;
        }
    }
    if(cnt%n == 0){
        if((cnt/n) % 2 == 1){
            cout<<cnt/n<<" "<<n;
        }else cout<<cnt/n<<" "<<1;
        return 0;
    }
    if(cnt%n != 0){
            int x = cnt/n;
        if(x % 2 == 1){
            cout<<x+1<<" "<<n-(cnt%n)+1;
        }else cout<<x+1<<" "<<cnt%n;
        return 0;
    }


    return 0;
}
