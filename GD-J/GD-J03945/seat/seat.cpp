#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],lie = 1,hang = 1,d = 0,a1,j = 1;
bool cmp(int b,int c){
	return b > c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d" ,&n,&m);
	for(int i = 1;i <= n * m;i++){
		scanf("%d" ,&a[i]);
	}
	a1 = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	while(1){
		if(a[j] == a1){
			printf("%d %d" ,lie,hang);
			return 0;
		}
		if(d == 0){
			hang++;
			if(hang == n){
				d = 1;
			}
		}else if(d == 1){
			lie++;
			d = 2;
		}else if(d == 2){
			hang--;
			if(hang == 1){
				d = 3;
			}
		}else if(d == 3){
			lie++;
			d = 0;
		}
		j++;
	}
}
