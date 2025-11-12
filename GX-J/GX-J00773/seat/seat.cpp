#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,inf=0x3f3f3f3f;
typedef long long ll;
int a[N];
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int score=0;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    score=a[1];
    sort(a+1,a+1+n*m,cmp);
    int id=0;
    for(int i=1;i<=n*m;i++)
        if(a[i]==score)
            id=i;
    int col=id/n;
    if(id%n!=0)col++;
    int row=0;
    if(col%2==1){
        row=id%m;
        if(!row)row++;
    }
    else row=n-score%m;
    cout<<col<<" "<<row;
    return 0;
}
