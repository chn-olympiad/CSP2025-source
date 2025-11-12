#include<bits/stdc++.h>
using namespace std;
int sc[1001];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
	int n,m,c,r,xm_sc;
	cin >> n >> m; 
	for(int i=1;i<=n*m;i++){
		cin >> sc[i];
		if(i == 1){
			xm_sc = sc[i];
		}
	}
	sort(sc+1,sc+(n*m)+1,cmp);
	int num = 0;
	for(int i=1;i<=n*m;i++){
		if(sc[i] == xm_sc){
			num = i;
		}
	}	
	c = (num-1) / n + 1;
	if(c % 2 == 1){
		num -= (c-1) * n; 
		r = num;
	}else{
		num -= (c-1) * n;
		r = n - num + 1;
	}
	cout << c << ' ' << r;
	return 0;
}
