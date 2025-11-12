#include<bits/stdc++.h>
using namespace std;
int n,m,l = 0,a[110];
int main(){
scanf("%d%d",&n,&m);
for(int i = 1;i <= n * m;i++)
    scanf("%d",&a[i]);
int p = a[1];
for(int i = 1;i <= n * m;i++)
for(int j = i + 1;j <= n * m;j++)
    if(a[i] < a[j])
        swap(a[i],a[j]);
for(int i = 1;i <= n * m;i++)
    if(a[i] == p)
       l = i;
int x = (l - 1) / n + 1;
printf("%d ",x);
int y = (l - 1) % n + 1;
if(x % 2 == 1){
   printf("%d",y);
}
else{
    printf("%d",n - y + 1);
}
}
