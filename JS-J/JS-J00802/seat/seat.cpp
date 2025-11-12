#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,r,t;
int a[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
    r=a[1],t=n*m;
    sort(a+1,a+t+1,greater<int>());
    int k=0,i=1,j=1;
    for(i=1;i<=n;i++){
		if(i%2==0)t=-1;
		else t=1;
		for(;j<=m&&j>=1;j+=t){
			k++;
			if(a[k]==r){
				printf("%d %d",i,j);
				return 0;
			}
		}
		if(j>m)j--;
		if(j<1)j++;
	}
    return 0;
}
