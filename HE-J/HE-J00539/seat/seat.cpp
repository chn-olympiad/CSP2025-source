#include <bits/stdc++.h>

using namespace std;
struct stu{
    int sum,id;

}a[110];
int n,m,a1[30][30],cnt=0;
bool cmp(stu a,stu b){
    return a.sum>b.sum;

}
int main()
{   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].sum;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
            cnt++;
            a1[j][i]=a[cnt].id;
            if(a1[j][i]==1){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
        }
        }
        else{
            for(int j=1;j<=n;j++){
            cnt++;
            a1[j][i]=a[cnt].id;
            if(a1[j][i]==1){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
        }
        }
    }
    return 0;
}
