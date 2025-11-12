//手握日月摘星辰，世间无我这般人 

#include<bits/stdc++.h>
using namespace std;

int n,m;
int h = 1,l = 1,f = 1;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int he = n*m;
	for(int i = 1;i <= he;i++){
		cin >> a[i];
	}
	
	sort(a + 2,a + 1 + he);
	
	for(int i = he;i >= 2;i--){
		if(a[1] < a[i]){
			h += f;
			if(h > n){
				f = -1;
				h--;
				l++;
			}
			if(h < 1){
				f = 1;
				h++;
				l++;
			}
		}
		else{
			cout << l << ' ' << h;
			break;
		}
	}
	return 0;
} 
