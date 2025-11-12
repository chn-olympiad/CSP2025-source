#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,sum=0,value,ans=0;
	cin >> n >> value;
	m[0]=1;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		sum^=num;
		m[sum]=1;
		if(m[sum^value]==1){
			m.clear();
			ans++;
			m[0]=1;
			sum=0;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
