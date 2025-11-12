#include <cstdio>
#include <algorithm>

int count =0;
int book[5005];
int box[5005];
int a[5005];

void dfs(int step ,int total ,int father,int max) {
    if (step > total) {
        int sum=0;
        for (int i = 1; i <= total; i++) {
            sum += box[i];
        }
        if (sum > 2*box[total]) {
            count++;
        }
        return;
    }
    

    for (int i = father+1; i <= max; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            box[step] = a[i];
            dfs(step+1,total,i,max);
            book[i] = 0;
        }
    }
    
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n+1);
    for (int i = 3; i <= n; i++) {
        dfs(1,i,0,n);
    }
    printf("%d",count%998244353);
    return 0;
}