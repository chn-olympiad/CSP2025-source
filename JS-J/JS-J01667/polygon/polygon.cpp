#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],mn,s,sumxy;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=3;i<=n;i++){
		for (int j=1;j<=n-i;j++){
			s=0;
			for (int x=j;x<=j+i;x++){
				s+=a[x];
				mn=max(mn,a[x]);
			}if (s>=mn*2){
				sumxy++;
				cout<<j<<' '<<i<<endl;
			}
		}
	}cout<<sumxy;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
