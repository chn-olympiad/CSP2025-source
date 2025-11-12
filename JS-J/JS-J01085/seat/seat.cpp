#include<bits/stdc++.h>
using namespace std;
int a[100001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cj=a[1];//xiao r chengji
    sort(a+1,a+n*m+1,cmp);
    int wc=0;//weici
    for(int i=1;i<=n*m;i++){
        if(a[i]==cj){
            wc=i;
            break;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                ans++;
                if(ans==wc){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                ans++;
                if(ans==wc){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
