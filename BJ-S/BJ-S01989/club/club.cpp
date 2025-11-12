#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct node{
    int x,y,z;
}p[100005];
int r[100005],s[100005],t[100005],R,S,T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> m;
    while(m--){
        cin >> n;
        cnt = 0,R = 0,S = 0,T = 0;
        for(int i = 1; i<= n; i++){
            cin >> p[i].x >> p[i].y >> p[i].z;
            if(p[i].x > p[i].y && p[i].x > p[i].z){
                cnt += p[i].x;
                R++;
                r[R] = p[i].x - max(p[i].y,p[i].z);
            }
            else if(p[i].y > p[i].x && p[i].y > p[i].z){
                cnt += p[i].y;
                S++;
                s[S] = p[i].y - max(p[i].x,p[i].z);
            }
            else{
                cnt += p[i].z;
                T++;
                t[T] = p[i].z - max(p[i].y,p[i].x);
            }
        }
        sort(r + 1,r + R + 1);
        sort(s + 1,s + S + 1);
        sort(t + 1,t + T + 1);
        if(R > n / 2){
            int st = R - n / 2;
            for(int i = 1; i<= st; i++){
                cnt -= r[i];
            }
        }
        if(S > n / 2){
            int st = S - n / 2;
            for(int i = 1; i<= st; i++){
                cnt -= s[i];
            }
        }
        if(T > n / 2){
            int st = T - n / 2;
            for(int i = 1; i<= st; i++){
                cnt -= t[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
