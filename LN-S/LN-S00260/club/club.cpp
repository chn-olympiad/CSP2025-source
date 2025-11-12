#include<bits/stdc++.h>
using namespace std; 

const int maxn = 1e5+20; 
int t; 
int n; 
struct node{
    long long a[5]; 
    int b1, b2; //which is best
    long long c12; //difference
}p[maxn]; 
int g1[maxn], g2[maxn], g3[maxn], pos1, pos2, pos3; //three groups

void find_best(int i, int a, int b, int c){
    if(a >= b && b >= c) p[i].b1 = 1, p[i].b2 = 2; 
    else if(a >= c && c >= b) p[i].b1 = 1, p[i].b2 = 3; 
    else if(b >= a && a >= c) p[i].b1 = 2, p[i].b2 = 1; 
    else if(b >= c && c >= a) p[i].b1 = 2, p[i].b2 = 3; 
    else if(c >= a && a >= b) p[i].b1 = 3, p[i].b2 = 1; 
    else p[i].b1 = 3, p[i].b2 = 2; 
    p[i].c12 = p[i].a[p[i].b2] - p[i].a[p[i].b1]; 
    return; 
} 

bool cmp(int a, int b){
    return p[a].c12 < p[b].c12; 
}

int main(){
    freopen("club.in", "r", stdin); 
    freopen("club.out", "w", stdout); 
    scanf("%d", &t); 
    while(t--){
        scanf("%d", &n); 
        memset(g1, 0, sizeof(g1)); 
        memset(g2, 0, sizeof(g2)); 
        memset(g3, 0, sizeof(g3)); 
        pos1 = 0, pos2 = 0, pos3 = 0; 
        for(int i = 1; i <= n+10; i++){
            p[i].a[1] = 0, p[i].a[2] = 0, p[i].a[3] = 0; 
            p[i].b1 = 0, p[i].b2 = 0; 
            p[i].c12 = 0; 
        }
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld%lld", &p[i].a[1], &p[i].a[2], &p[i].a[3]); 
            find_best(i, p[i].a[1], p[i].a[2], p[i].a[3]); 
            if(p[i].b1 == 1) g1[++pos1] = i; 
            else if(p[i].b1 == 2) g2[++pos2] = i; 
            else g3[++pos3] = i; 
        }
        long long ans = 0; 
        for(int i = 1; i <= pos1; i++){
            int pos = g1[i]; 
            ans += p[pos].a[p[pos].b1];
        }
        for(int i = 1; i <= pos2; i++){
            int pos = g2[i]; 
            ans += p[pos].a[p[pos].b1]; 
        }
        for(int i = 1; i <= pos3; i++){
            int pos = g3[i]; 
            ans += p[pos].a[p[pos].b1];  
        }
        if(pos1 <= n/2 && pos2 <= n/2 && pos3 <= n/2){
            printf("%lld\n", ans);
        }else{
            if(pos1 > n/2){
                sort(g1+1, g1+pos1+1, cmp);
                while(pos1 > n/2){
                    int now = g1[pos1--]; 
                    ans += p[now].c12; 
                }
            }else if(pos2 > n/2){
                sort(g2+1, g2+pos2+1, cmp); 
                while(pos2 > n/2){
                    int now = g2[pos2--]; 
                    ans += p[now].c12; 
                }
            }else{
                sort(g3+1, g3+pos3+1, cmp); 
                while(pos3 > n/2){
                    int now = g3[pos3--]; 
                    ans += p[now].c12; 
                }
            }
            printf("%lld\n", ans); 
        }
    }
    return 0; 
}