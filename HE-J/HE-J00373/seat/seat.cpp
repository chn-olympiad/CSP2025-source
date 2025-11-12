#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
	}
	int p,x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=1,j=1,f=1;
	for(int k=1;k<=n*m;k++){
        if(i==n+1){
            i=n,j++,f=-1;
        }
        if(i==0){
            i=1,j++,f=1;
        }
        if(a[k]==x){
            printf("%d %d\n",j,i);
            break;
        }
        i+=f;
	}
	return 0;
}
