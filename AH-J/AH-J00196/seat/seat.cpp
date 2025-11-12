#include<bits/stdc++.h>
using namespace std;
int a[1005];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int len=n*m;
    for (int i=1;i<=len;i++){
        cin>>a[i];
    }
    int rsc=a[1];
    sort(a+1,a+len+1,cmp);
    int pos;
    for (int i=1;i<=len;i++){
        if (a[i]==rsc){
            pos=i;
            break;
        }
    }
    int lie=(pos%n==0 ? pos/n:pos/n+1);
    int hang=(lie%2==0 ? n-(pos-(lie-1)*n)+1:pos-(lie-1)*n);
    cout<<lie<<" "<<hang;
    return 0;
}
