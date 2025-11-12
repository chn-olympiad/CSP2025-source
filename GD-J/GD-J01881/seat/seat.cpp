#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	vector<int> v(n*m);
	for(auto &i:v) cin >> i;
	
	int R = v[0];
	
	sort(v.begin(),v.end(),[](int a,int b){
		return a>b;
	});
	
	for(int i=0;i<n*m;i++){
		if(v[i]!=R) continue;
		cout << i/n + 1 << ' ';
		int t = i%n;
		if((i/n)&1){
			cout << m - t << '\n';
		}
		else cout << t + 1 << '\n';
		
		break;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
