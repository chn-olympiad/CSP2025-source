#include<bits/stdc++.h>
using namespace std;

struct data{
    int n;
    int a[100005][4];
};

void input(data& x){
    cin>>x.n;
    for(int i=1; i<=x.n; i++){
        cin>>x.a[i][1]>>x.a[i][2]>>x.a[i][3];
    }
}

int getmax(int x1, int x2, int x3, bool ok1, bool ok2, bool ok3){
    if(ok1 && ok2 && ok3){
        if(x1>=x2 && x1>=x3){
            return 1;
        }else if(x2>=x1 && x2>=x3){
            return 2;
        }else if(x3>=x1 && x3>=x2){
            return 3;
        }
    }else if(!ok1 && ok2 && ok3){
        if(x2>=x3) return 2; else return 3;
    }else if(ok1 && !ok2 && ok3){
        if(x1>=x3) return 1; else return 3;
    }else if(ok1 && ok2 && !ok3){
        if(x1>=x2) return 1; else return 2;
    }else if(!ok1 && !ok2 && ok3){
        return 3;
    }else if(!ok1 && ok2 && !ok3){
        return 2;
    }else if(ok1 && !ok2 && !ok3){
        return 1;
    }
}

//a[i][3]==0
int getmax2(int x1, int x2, int x3, bool ok1, bool ok2, bool ok3){
    if(ok1 && ok2){
        return (x1>=x2 ? 1 : 2);
    }else if(!ok1 && ok2){
        return 1;
    }else if(ok1 && !ok2){
        return 2;
    }else if(!ok1 && !ok2){
        return 3;
    }
}

int test(data x){
    int ans = 0;
    int c[4] = {0};
    bool ok[4] = {1,1,1,1};
    for(int i=1; i<=x.n; i++){
        int Max = getmax(x.a[i][1],x.a[i][2],x.a[i][3],ok[1],ok[2],ok[3]);
        c[Max]++;
        if(c[Max]==x.n/2) ok[Max]=0;
        ans += x.a[i][Max];
    }
    return ans;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        data d;
        input(d);
        cout<<test(d)<<endl;
    }
    return 0;
}
