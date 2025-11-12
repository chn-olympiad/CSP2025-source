#include<iostream>
using namespace std;
struct node{
	int num;
	bool flag=0;
};
node a[600010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int sum=0,outside=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		if(a[i].num==k){
			sum++;
			a[i].flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		int ex_or=0;
		bool torf=0;
		for(int j=i;j<=n;j++){
			if(a[j].flag==0){
				ex_or^=a[j].num;
				if(ex_or==k){
					sum++;
					break;
				}
			}else{
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}