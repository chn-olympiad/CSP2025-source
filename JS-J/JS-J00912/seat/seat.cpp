#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[114];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int cnt=0,ra=1;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) ra++;
    }
    //cout<<ra<<'\n';
    for(int lie=1;lie<=m;lie++){
        if(lie%2==1){
            for(int hang=1;hang<=n;hang++){
                cnt++;
                if(cnt==ra){
                    cout<<lie<<' '<<hang<<'\n';
                    return 0;
                }

            }
        }
        else{
            for(int hang=n;hang>=1;hang--){
                cnt++;
                if(cnt==ra){
                    cout<<lie<<' '<<hang<<'\n';
                    return 0;
                }

            }
        }
    }
    return 0;
}
