#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000000],ans = 0;
int tmps[10000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	int tmp = 0;
	for(int i=0;i<n;i++){
		if(a[i] == k){
			ans++;
			tmp = 0;
			continue;
		}
		tmp ^= a[i];
		if(tmp == 0 && a[i] != 0){
			tmp = a[i];
		}
		if(tmp == k){
			ans++;
			tmp = 0;
		}
	}
	//cout << endl;
	cout << ans;
	return 0;
}
	
	
/*
#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000000],ans = 0;
int tmps[10000000];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	int tmp = 0;
	for(int i=0;i<n;i++){
		if(a[i] == k){
			ans++;
			tmp = 0;
			continue;
		}
		tmp ^= a[i];
		if(tmp == 0 && a[i] != 0){
			tmp = a[i];
		}
		if(tmp == k){
			ans++;
			tmp = 0;
		}
	}
	//cout << endl;
	cout << ans;
}
	
*/
