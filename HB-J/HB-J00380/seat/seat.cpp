#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
bool f(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    int ilove37=a[1],cute37;
    sort(a+1,a+n*m+1,f);
    for(int i=1;i<=n*m;i++){
        if(a[i]==ilove37){
            cute37=i;
            break;
        }
    }
    int hang=cute37%n,lie=cute37/n+1;
    if(hang==0){
        hang=n;
        lie--;
    }
    printf("%d %d",lie,hang);
    return 0;
}
