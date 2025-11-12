#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
int n,m,k;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&k);
	printf("%d",rand()%(k/(n*m)));
	return 0;
}

