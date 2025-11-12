#include<bits/stdc++.h>
using namespace std;
const int N = 5500;
int n,a[N],cnt,b,c,d,e,f,g;
bool flag = true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			flag = false;
		}
	}
	if(flag){
		b = 1;
		for(int i=1;i<n;i++){
			b*=2;
			b%=998244353;
		}
		cout <<b;
		return 0;
	}
	b = 1<<n;
	c = 1;
	while(c<b){
		d = b;
		e = 0;
		f = -1;
		g = n;
		while(g+1){
			if((1<<g)&c){
				e += a[g+1];
				f = max(f,a[g+1]);
//				cout << a[g] << " ";
			}
			g--;
		}
		if(e>f*2){
			cnt ++;
//			cout << "GET\n";
		}
//		else cout <<"NOT\n";
		c++;
	}
	cout << cnt;
}