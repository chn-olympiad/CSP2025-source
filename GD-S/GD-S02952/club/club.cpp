#include<bits/stdc++.h>
using namespace std;
struct man{
    int a;
    int b;
    int c;
    int maxn;
    int chahe;
}arr[100005];
int n;
bool cmp(man a,man b){
    if(a.chahe != b.chahe)
    	return a.chahe > b.chahe;
    return a.maxn > b.maxn;
}
man a1[50005],b1[50005],c1[50005];
int a2 = 0,b2 = 0,c2 = 0,N,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
            arr[i].maxn = max(arr[i].a,max(arr[i].b,arr[i].c));
            if(arr[i].maxn == arr[i].a)
                arr[i].chahe = arr[i].maxn - max(arr[i].b,arr[i].c);
            else if(arr[i].maxn == arr[i].b)
                arr[i].chahe = arr[i].maxn - max(arr[i].a,arr[i].c);
            else
                arr[i].chahe = arr[i].maxn - max(arr[i].a,arr[i].b);
        }
        N = n / 2;
        sort(arr+1,arr+n+1,cmp);
        for(int i = 1;i<=n;i++){
            if(arr[i].maxn == arr[i].a){
                if(a2 < N){
                    a1[++a2] = arr[i];
                    ans += arr[i].a;
                }
                else if(arr[i].b >= arr[i].c){
                    b1[++b2] = arr[i];
                    ans += arr[i].b;
                }
                else{
                    c1[++c2] = arr[i];
                    ans += arr[i].c;
                }
            }
            else if(arr[i].maxn == arr[i].b){
                if(b2 < N){
                    b1[++b2] = arr[i];
                    ans += arr[i].b;
                }
                else if(arr[i].a >= arr[i].c){
                    a1[++a2] = arr[i];
                    ans += arr[i].a;
                }
                else{
                    c1[++c2] = arr[i];
                    ans += arr[i].c;
                }
            }
            else
                if(c2 < N){
                    c1[++c2] = arr[i];
                    ans += arr[i].c;
                }
                else if(arr[i].a >= arr[i].b){
                    a1[++a2] = arr[i];
                    ans += arr[i].a;
                }
                else{
                    b1[++b2] = arr[i];
                    ans += arr[i].b;
                }
        }
        printf("%d\n",ans);
        a2 = 0;	b2 = 0;	c2 = 0;	ans = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
