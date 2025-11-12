#include <bits/stdc++.h>
using namespace std;
const int NM=105;
int n,m;
int a[NM];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int r,c,yu=0;
    scanf("%d%d",&n,&m);
    int people=n*m;
    for(int i=1;i<=people;i++)
        scanf("%d",&a[i]);
    int x=a[1];
    sort(a+1,a+1+people,cmp);
    for(int i=1;i<=people;i++){
        if(a[i]==x){
            if(i%n!=0)
                c=i/n+1,yu=i%n;
            else
                c=i/n,yu=n;
            if(c%2!=0)
                r=yu;
            else
                r=n-yu+1;
        }
    }
    printf("%d %d",c,r);
    fclose(stdin);
    fclose(stdout);
    return 0;

}
