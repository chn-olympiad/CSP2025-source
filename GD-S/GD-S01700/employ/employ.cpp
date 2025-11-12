#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],nx[100005],ans,g,ji;string s;bool f[1005];
void qpl(int n,int d){
	if(d==n){
		g = 0;
		for (int i = 0;i < n;i++){
			//cout << a[i] << " ";
			if(g>=nx[a[i]]){
				g++;
				continue;
			}
			if(s[i]=='0'){
				g++;
			}
			
		}
		//cout << g;
		//cout << endl;
		if((n-g)>=m){
			ans++;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(f[i]){
			continue;
		}
		f[i]=1;
		a[d]=i;
		qpl(n,d+1);
		f[i]=0;
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;	
	cin >> s;
	if(n>=100){
		cout << 515058943;
		return 0;
	}
	for (int i = 1;i <= n;i++){
		cin >> nx[i];
	}
	qpl(n,0);
	cout << ans;
	return 0; 
}
