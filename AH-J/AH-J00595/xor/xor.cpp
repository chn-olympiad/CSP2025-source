#include<bits/stdc++.h>
using namespace std;
int n,a[500500],b[500500],k,p,sans,cnt;
struct node{
    int x;
    int y;
}c[500500];
bool cmp(node a,node b){
    return a.y<b.y;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]^b[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((b[i-1]^b[j])==k){
                cnt++;
                c[cnt].x=i;
                c[cnt].y=j;
            }
        }
    }
    sort(c+1,c+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        if(c[i].x>p){
            p=c[i].y;
            sans++;
        }
    }
    printf("%d",sans);
    return 0;
}
/*
最后一个样例报错了(noi linux 2.0 )：
Segmentation fault (core dumped)
有dalao解释下是怎么回事么
O(N^2) 算法 估60pts 目前260pts

*只有最后一个大样例没过使你充满了?
*You can buy Undertale for just 9 yuan on Steam before Nov. 4th!
*Well,you might missed it...
*/
