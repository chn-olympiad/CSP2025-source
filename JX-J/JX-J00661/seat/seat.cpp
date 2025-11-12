#include<bits/stdc++.h>
using namespace std;
const int N=105;
int arr[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int save;
    int zong=n*m;
    arr[0]=200;
    for(int i=1;i<=zong;i++){
        cin>>arr[i];
    }
     save=arr[1];
    int pos;
    sort(arr,arr+zong,cmp);
    for(int i=1;i<=zong;i++){
        if(arr[i]==save){
            pos=i;
            break;
        }
    }
    //cout<<pos<<endl;
    int hang,lie;
    int cnt=0;
    bool flag=false;
    for(int i=1;i<=m;){
        for(int j=1;j<=n;j++){
                cnt++;
        //cout<<i<<" "<<j<<" " <<cnt<<endl;
            if(pos==cnt){
                hang=j;
                lie=i;
                flag=true;
                break;
            }

        }
        if(flag){
            break;
        }
        i++;
        cnt++;
        //cout<<i<<" "<<n<<" " <<cnt<<endl;
        if(pos==cnt){
            hang=n;
            lie=i;
            break;
        }
        for(int j=n-1;j>=1;j--){
                //cout<<i<<" "<<j<<" " <<cnt<<endl;
                cnt++;
            if(pos==cnt){
                hang=j;
                lie=i;
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
        i++;
        cnt++;
        //cout<<i<<" "<<1<<" " <<cnt<<endl;
        if(pos==cnt){
            hang=1;
            lie=i;
            break;
        }
    }
    cout<<lie<<" "<<hang;
    return 0;
}
