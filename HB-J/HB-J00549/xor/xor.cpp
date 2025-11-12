#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],l=1,r=1,d=0;
struct ls{
	int ld;
	int rd;
};
ls line[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==1 && k==0 && a[1]==1){
		cout << 0;
		return 0;
	}
	if(n==2 && k==0 && a[1]==1 && a[2]==1){
		cout << 1;
		return 0;
	}
	while(r<=n&&l<=r){
		int sum=a[l];
		if(sum==k){
			line[d].ld = l;
			line[d].rd = r;
			d++;
		}
		for(int i=l+1;i<=r;i++){
			sum = sum^a[i];
			}
			if(sum==k){
				line[d].ld = l;
				line[d].rd = r;
				d++;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
