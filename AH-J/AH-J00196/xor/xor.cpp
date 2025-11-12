#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t;

struct node{
    int st,ed;
}qujian[500005];

int work(int x,int y){
    int n=max(x,y);
    int k=1;
    int sum=0;
    while (n){
      int a=x%2;
      int b=y%2;
      if (a!=b){
        sum+=k*1;
      }
      else{
        sum+=k*0;
      }
      x/=2;
      y/=2;
      n/=2;
      k*=2;
    }
    return sum;
}

bool cmp(node x,node y){
    if (x.ed!=y.ed){
        return x.ed<y.ed;
    }
    return x.st>y.st;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool judgeA=true;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=1){
            judgeA=false;
        }
    }
    //Special A
    if (judgeA){
        if (k!=0&&k!=1){
            cout<<0;
        }
        else{
            //if there are n*1
            //n%2==1 --> 1
            //n%2==0 --> 0
            if (k==0){
                cout<<n/2;
            }
            else{
                cout<<n;
            }
        }
    }

    else{
        for (int i=1;i<=n;i++){
            int nowxor=a[i];
            if (nowxor==k){
                qujian[++t].st=i;
                qujian[t].ed=i;
                continue;
            }
            for(int j=i+1;j<=n;j++){
                nowxor=work(nowxor,a[j]);
                if (nowxor==k){
                    qujian[++t].st=i;
                    qujian[t].ed=j;
                    break;
                }
            }
        }
        sort(qujian+1,qujian+t+1,cmp);
        int ans=1;
        int nowed=qujian[1].ed;
        for (int i=2;i<=t;i++){
            if (qujian[i].st>nowed){
                ans++;
                nowed=qujian[i].ed;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
