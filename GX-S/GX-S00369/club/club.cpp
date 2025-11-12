# include<bits/stdc++.h>
using namespace std;

typedef struct Link{
    int a;
    int b;
    int c;
}Link;

int asi, maxl[10], u;
void DFS(int sum, int post, Link arr[], int p1, int p2, int p3){
    if(post == asi){
        if(sum > maxl[u]){
            maxl[u] = sum;
        }
        return;
    }
    if(p1+1 <= asi/2){
        DFS(sum+arr[post].a, post+1, arr, p1+1, p2, p3);
    }
    if(p2+1 <= asi/2){
        DFS(sum+arr[post].b, post+1, arr, p1, p2+1, p3);
    }
    if(p3+1 <= asi/2){
        DFS(sum+arr[post].c, post+1, arr, p1, p2, p3+1);
    }
    return;
}

int main(void){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d", &t);
    for ( int q = 0;  q < t ; q++ ){
        int n;
        scanf("%d", &n);
        Link arr[n];
        for ( int i = 0 ; i < n ; i++ ){
            scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
        }
        asi = n;
        DFS(0,0,arr,0,0,0);
        u++;

    }
    for ( int i = 0 ; i < t ; i++ ){
        printf("%d\n", maxl[i]);
    }
    return 0;
}
