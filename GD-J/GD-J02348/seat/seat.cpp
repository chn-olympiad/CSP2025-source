#include <iostream>
using namespace std;

const int MAXN=105;

int n,m,r=1,c=1;

int num[MAXN];

bool flag;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&num[i]);
	}
	for (int i=2;i<=n*m;i++){
		if (num[i]>num[1]){
			if (!flag){
				r++;
				if (r>n){
					r--;
					c++;
					flag=1;
				} 
			}
			else{
				r--;
				if (!r){
					r++;
					c++;
					flag=0;
				}
			}
		}
	}
	printf("%d %d",c,r);
	return 0;
}
