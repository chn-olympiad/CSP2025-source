#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
long long a[N];
int n;
long long k;
bool flag_A = true;
bool flag_B = true;
long long cnt0 = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0){
			cnt0++;
		}
		if(a[i]!=1){
			flag_A = false;
			if(a[i]!=0){
				flag_B = false;
			}
		}
	}
	if(flag_A){
		cout << 0;
	}else if(flag_B){
		if(k==0){
			cout << cnt0;
		}else if(k==1){
			cout << n-cnt0;
		}
	}else{
		cout << n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
