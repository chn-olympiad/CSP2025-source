#include<bits/stdc++.h>
using namespace std;
const int N  = 120;
int a[N];
int n,m;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c = ceil(9 *1.0/2);
	
	cin >> n >> m;
	int cnt = n*m;
	for(int i =1;i <= cnt;i++){
		cin >> a[i];
	}
	int r = a[1];
	
	sort(a+1,a+1+cnt,cmp);
	int score;
	for(int i = 1;i <= cnt;i++){
		
		if(a[i] == r){
			score = i;
			break;
		}
	}
	
	int h,l;
	l = ceil(score *1.0/n);
	
	if(l % 2 == 1){
		if(score <= n){
			h = score;
		}else{
			if(score % n == 0){
				h = n;
			}else{
				h = score % n;
		
			}
		}
		
	}else{
		if(score % n != 0){
			h = (n - (score % n))+1;
		}else{
			h = 1;
		}
	}
	cout<< l<<" "<<h;

	return 0;
} 
