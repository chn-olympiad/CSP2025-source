#include<bits/stdc++.h>
#define N 505
using namespace std;
using ll=long long;
int n,m;
string s;
int c[N],dif[N],serial[N];
bool used[N];
ll ans=0;
int check(){
    //for(int i=1;i<=n;i++) cout<<serial[i]<<' ';cout<<endl;
    int employee=0,unacceptable=0;
    for(int i=1;i<=n;i++){
        if(unacceptable>=c[serial[i]]){
            unacceptable++;
        }else{
            //printf("Day:%d whose s[i]=%d: check %d whose c[i]=%d, fired=%d, employed=%d\n",i,dif[i],serial[i],c[serial[i]],unacceptable,employee);
            if(dif[i]==1){
                employee++;
                if(employee>=m) return 1;
            }else{
                unacceptable++;
            }
        }
    }
    //cout<<"==============\n";
    return 0;
}
void arrange(int index){
    if(index==n+1){
        ans+=check();
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            serial[index]=i;
            arrange(index+1);
            used[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>s;s=" "+s;
    for(int i=1;i<=n;i++){
        dif[i]=(s[i]=='1');
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    arrange(1);
    cout<<ans;
    return 0;
}
