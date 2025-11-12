#include<iostream>
#include<algorithm>
using namespace std;
int a[10005];
int n,m;
bool cmp(int x,int y){
	return x > y;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;++i){
		cin >> a[i];
	}
	int lr = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(lr == a[i]){
			cout << y << ' ' << x;
			return 0;	
		} else{
			if(y % 2 == 1){
				int nx = x + 1;
				if(nx > n){
					y++;	
				} else{
					x++;	
				}
			} else{
				int nx = x - 1;
				if(nx < 1){
					y++;
				} else{
					x--;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

