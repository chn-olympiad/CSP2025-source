#include <iostream>
using namespace std;
int n,k,a[500005],sum=0,cnt=0,last;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		sum=a[i];
		last=i;
		for(int j = last;j <= n-1;j++){
			if(j != 1 && j <= last){
				continue;
			}
			a[j]^=a[j+1];
			if(a[j] == k){
				cnt++;
			}
			if(sum == k){
				cnt++;
			}
			last=j;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
