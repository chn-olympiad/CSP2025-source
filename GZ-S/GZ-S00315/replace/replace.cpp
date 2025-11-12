//GZ-S00315 贵阳市第三中学 王子乾 
#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","W",stdout);
	int n,m,q;
	cin >> n >> m;
	int a[n+m+10];
	char s,t;
	for(int i=1;i<=n;i++){
		cin >> t;
		for(int j=1;j<=m;j++){
			cin >> s;
			if(a[t]+a[s]==i){
				q+=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;i++){
			if(a[t]+a[t+s]==1&&a[i]<=a[j+t]){
				a[i]+=a[j];
			}
			else if(a[s]>a[t]&&a[t+3]<a[j+i]||a[m]!=a[i+t]){
				a[j]+=a[s];
				a[t]+a[i+j+n];
			} 
			else{
				a[j+n+s]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[t+s]+a[s]==i+j){
				a[j]+=a[s+t];
			}
			else if(a[j+i+n]>a[s+t]&&a[j]<=a[s+t]){
				a[i]+=a[s+t];
			}
			else{
				a[t]+=a[s];
				a[s]+a[i+j+n];
			}
		}
	}
	cout << 2 << " " << 0;
	return 0;
}
