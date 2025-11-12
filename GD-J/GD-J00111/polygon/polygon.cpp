#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
int n;
bool flag = false;
long long arr[N];
long long pre[N];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	
	for (int i = 1;i <= n;i++){
		cin >> arr[i];
		pre[i] = pre[i-1]+arr[i];	
	}
	for (int i = 1;i <=n;i++){
		cout << pre[i] << " ";
	}
	sort(arr+1,arr+1+n);
	for (int i = 3;i <= n;i++){
		if (pre[i-1] <= arr[i]){
			continue;
		}
		int j = i-2;
		while (j > 0){
			if (pre[j] <= arr[i]){
				break;
			}
			else{
				cout << "j" << j <<endl;
				ans++;
				j--;
			}
		}
		
		
		
		int k = i - 1;
		int pt = i -2;
		cout << "i" << i << endl;
		while (pt > 0){
			cout << pre[k] << " " << pre[pt] << endl;
			if (pre[k] - pre[pt] <= arr[i]){
				pt--;
				while (pt>0){
					if (arr[pt]+arr[k] >= arr[i]) ans++;
					cout << "asdnfasd" << ans << endl;
					pt--;
				}
				continue;
			}
			else{
				if (i+1 <= n && pre[k] - pre[pt] > arr[i+1]) ans += (pt+1);
				ans += (pt+1);
				cout << "ans" << ans << endl;
				pt--;
				if (pt == 1) break;
			}
		}
		
	}
	cout << ans << endl;
	return 0;
}
