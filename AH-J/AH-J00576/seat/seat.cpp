#include <bits/stdc++.h>
using namespace std;
struct student{
	int id,socer;
	bool operator < (student A){
		return socer > A.socer;
	}
} a[200];
int n,m,R;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].socer);
		a[i].id=i;
    }sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
		if(a[i].id==1)
			R=i;
	} if(((R-1)/n+1)%2){
		printf("%d %d",(R-1)/n+1, R-((R-1)/n)*n);
	}else{
		printf("%d %d",(R-1)/n+1, n-R+((R-1)/n)*n+1);
	}
}
