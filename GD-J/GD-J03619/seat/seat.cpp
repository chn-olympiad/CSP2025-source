#include <bits/stdc++.h>
using namespace std;

bool f=0;
int n,m;
int c=1,r=1;
int a[200];

bool cmp(int x,int y){return x>y;} 

void main2(){
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){	
		cin >> a[i];
	}int xr = a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1;
	for(int k=1;k<=n*m;k++){		
		if(a[k]==xr){
			c = j,r = i;
			break;
		}
		if(f) i--;
		else i++;
		if(i > n){
			j++;
			i -= 1;
			f = 1;	
		}else if(i < 1){
			j++;
			i += 1;
			f = 0;
		}
	}cout << c << ' ' << r;
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	main2();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
