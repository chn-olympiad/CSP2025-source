#include<cstdio>
#include<algorithm>

int a[5100],l[5100];

int main(){
	std::freopen("polygon.in","r",stdin);
	std::freopen("polygon.out","w",stdout);
	int n,sum=0,amin=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		amin=std::min(amin,a[i]);
	}if(sum>amin*2) printf("1");
	return 0;
}
