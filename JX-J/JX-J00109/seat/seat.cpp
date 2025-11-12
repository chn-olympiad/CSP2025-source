#include<bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int flag;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    flag=a[1];
    int cnt;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==flag){
            cnt=i;
            break;
        }
    }
    int hang=(cnt-1)/m+1;
    int lie;
    if(hang%2!=0) lie=(cnt-1)%n+1;
    else lie=n-(cnt-1)%n;

    cout<<hang<<" "<<lie<<endl;
    return 0;
}
