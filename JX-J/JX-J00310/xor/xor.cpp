#include<cstdio>
using namespace std;
int n,k,numa,numb;
int ay[105];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++) {
        scanf("%d",ay[i]);
        if (ay[i]==1) numb++;
        else if (ay[i]==0) numa++;
    }
    if (k==0) printf("%d",numa);
    else printf("%d",numb);
    return 0;
}
