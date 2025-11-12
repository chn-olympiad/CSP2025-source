#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a,s=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a1);
    for(int i=1;i<m*n;i++){
        scanf("%d",&a);
        if(a>a1){
		    s++;
		}
    }
    printf("%d %d",s/n+1,s%n+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
