#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[5000005],cnt,num;
struct note{
    int st,ed;
};
note b[50000005];
bool cmd(note x,note y){
    if (x.st=y.st) return x.ed<y.ed;
    return x.st<y.st;
}
int main(){
    freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int ans=0;
        for(int j=i;j<=n;j++){
            ans=ans^a[j];
            if(ans==k){
                num++;
                b[num].st=i,b[num].ed=j;
            }
        }
    }
    sort(b+1,b+1+num,cmd);
    int lst=0,led=0;
    for(int i=1;i<=num;i++){
        if(b[i].st>led){
            cnt++;
            lst=b[i].st;
            led=b[i].ed;
            //cout<<lst<<" "<<led<<endl;
        }
    }
    cout<<cnt;
    return 0;

}
