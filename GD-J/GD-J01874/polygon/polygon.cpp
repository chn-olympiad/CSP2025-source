#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,cnt = 0;
	bool pd = true;
	cin>>n;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] != 1) pd = false;
	}
	if(pd){
		cout<<n - 2;
		return 0;
	}
	pd = true;
	for(int i = 0;i < n;i++){
		if(a[i] != 0) pd = false;
	}
	if(pd){
		cout<<0;
		return 0;
	}
	if(n == 3){
		if(a[0] + a[1] > a[2]){
			if(a[0] + a[2] > a[1]){
				if(a[1] + a[2] > a[0]){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0;
				return 0;
			}
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n == 4){
		int cnt = 0;
		if(a[0] + a[1] > a[2]){
			if(a[0] + a[2] > a[1]){
				if(a[1] + a[2] > a[0]){
					cnt++;
				}
			}
		}
		if(a[0] + a[1] > a[3]){
			if(a[0] + a[3] > a[1]){
				if(a[1] + a[3] > a[0]){
					cnt++;
				}
			}
		}
		if(a[0] + a[3] > a[2]){
			if(a[0] + a[2] > a[3]){
				if(a[3] + a[2] > a[0]){
					cnt++;
				}
			}
		}
		if(a[3] + a[1] > a[2]){
			if(a[3] + a[2] > a[1]){
				if(a[1] + a[2] > a[3]){
					cnt++;
				}
			}
		}
		if(a[0] + a[1] + a[2] > a[3]){
			if(a[0] + a[1] + a[3] > a[2]){
				if(a[0] + a[3] + a[2] > a[1]){
					if(a[3] + a[1] + a[2] > a[0]){
						cnt++;
					}
				}
			}	
		}
		cout<<cnt;
		return 0;
	}
	cout<<1;
	return 0;
}
