#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int y=0,cnt=0,p;
	while(1) {
		int i=y+1,j=i;
		if(i>n) break;
		p=a[i];
		while(1) {
			if(p<k) {
				p^=a[++j];
			}
			else if(p>k&&i<j) {
				p^=a[i++];
			}
			else if(p>k&&i>=j) {
				y=j;
				break;
			}
			else if(p==k) {
				cnt++;
				y=j;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
