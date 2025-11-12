#include <iostream>

using namespace std;
int n;
int l[100005];
int cnt;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>l[i];
    }
    int j=1;
    int sumn=0;
    int maxn=0;
    for(int i=3;i<=n;i++){
        while(j+i<=n+1){
            for(int k=j;k<j+i;k++){
                sumn+=l[k];
                cout<<l[k]<<" ";
                maxn=max(l[k],maxn);
            }
            cout<<"  ";
            if(sumn>maxn*2){
                cnt++;
            }
            sumn=0;
            maxn=0;
            j++;
        }
        j=1;
    }
    cout<<cnt%998244353;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

