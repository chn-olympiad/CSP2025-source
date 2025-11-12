#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 1e7 + 10;
int n,m,T,temp,idx;
int a[N],b[N],c[N],pre[N],ne[M];

struct node{
    int i;
    int pone;
    int ptwo;
    int pthree;
    int v;
};
node to[M];

void form_add(int i,int pone,int ptwo,int pthree,int ans){
    idx++;
    to[idx].i = i,to[idx].pone = pone,to[idx].ptwo = ptwo,to[idx].pthree = pthree,to[idx].v = ans;
    ne[idx] = pre[i];
    pre[i] = idx;
}

bool Find(int i,int pone,int ptwo,int pthree){
    node u;
    for(int j = pre[i];j;j = ne[j]){
        u = to[j];
        if(u.i == i && u.pone == pone && u.ptwo == ptwo && u.pthree == pthree){
            temp = u.v;
            return true;
        }
    }
    return false;
}

int f(int i,int pone,int ptwo,int pthree){
    //base case
    if(i > n) return 0;
    temp = 0;
    if(Find(i,pone,ptwo,pthree) == true) return temp;
    int ans = 0;
    if(pone < m) ans = max(ans,a[i] + f(i + 1,pone + 1,ptwo,pthree));
    if(ptwo < m) ans = max(ans,b[i] + f(i + 1,pone,ptwo + 1,pthree));
    if(pthree < m) ans = max(ans,c[i] + f(i + 1,pone,ptwo,pthree + 1));
    form_add(i,pone,ptwo,pthree,ans);
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        m = n / 2;
        cout << f(1,0,0,0) << endl;
        //end
        for(int i = 1;i<M;i++) pre[i] = 0,ne[i] = 0;
        idx = 0;

    }
    return 0;
}
