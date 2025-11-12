#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define dep(i,a,b) for(int i = a;i >= b;i--)
using namespace std;
int n,k;
int a[500005],qz[500005];
struct node{
    int l;
    int r;
    friend bool operator<(node a,node b){
        return a.l < b.l;


    }
}yh[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    rep(i,1,n){
        cin >> a[i];
        qz[i] = qz[i-1] xor a[i];
    }
    int num = 0;
    rep(i,1,n){
        rep(j,i,n){
            if((qz[j] xor qz[i-1]) == k){
                yh[++num].l = i;
                yh[num].r = j;
                break;
            }
        }
    }
    int sum = 0;
    sort(yh+1,yh+1+num);




    int j = 1;
    int i = yh[j].l;
    while(i < n){
        //cout << i << endl;
        sum++;
        i = yh[j].r;

        rep(k,j+1,num){
            if(yh[k].l > yh[j].r){
                j = k;
              //  cout << yh[j].l <<' '<< j << endl;
                break;
            }
        }


    }
    cout << sum;

    return 0;
}
