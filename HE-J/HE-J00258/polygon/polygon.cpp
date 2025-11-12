//手握日月摘星辰，世间无我这般人 

#include<bits/stdc++.h>
using namespace std;

int n,a[10000],he[10000];
long long ans = 0;
bool f[10000];
int h = 0,num;
int xx,w;
int b[1000];

void pri(){
	for(int i = 1;i <= xx;i++){
		cout << b[i] <<' ';
	}
	cout << endl;
}

void web(int x){
	if(x == xx + 1){
		if(h > 2 * num)ans++;
		return;
	}
	for(int i = w;i <= n;i++){
		if(!f[i]){
			f[i] = 1;
			h += a[i];
			w = i;
			num = a[i];
			web(x + 1);
			h -= a[i];
			f[i] = 0;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		he[i] = he[i - 1] + a[i];
	}

	sort(a + 1,a + 1 + n);
	
	for(int i = 3;i <= n;i++){
		xx = i;
		w = 1;
		web(1);
	}
	cout << ans;
	return 0;
} 
