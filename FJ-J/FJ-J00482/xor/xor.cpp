#include<iostream>
using namespace std;
int n,k,a[500005],r,q,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int l = 0;l < n;l++){
		r = 0;
		q = 0;
		while((q <= k) && (r < n)){
			q = q^a[l+r];
			if(q == k){
				ans++;
				l += r;
				break;
			}
			r++;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


