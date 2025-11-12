#include<iostream>
using namespace std;
int n,m,ar,k,num = 1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> ar;
	for(int i = 2;i <= n * m;i++){
		cin >> k;
		if(k > ar){
			num++;
		}
	}
	int mm = 0,nn = 0;
	if(num % n == 0){
		mm = num / n;
		if(num / n % 2 == 1){
			nn = n;
		}else{
			nn = 1;
		}
	}else{
		mm = num / n + 1;
		if(mm % 2 == 1){
			nn = num % n;
		}else{
			nn = n + 1 - (num % n);
		}
	}
	cout << mm << " " << nn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

