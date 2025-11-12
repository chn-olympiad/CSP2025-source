#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[100005],b[100005],c[100005],d[100005],n,t;
int search(int d1){
	for (int i=1;i<=n;i++){
		if(a[i]+b[i]+c[i]==d1){
			return i;
		}
	}
}
int main(){
	freopen("club.in","r", stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		for (int j=1;j<=n;j++){
			cin >> a[j] >> b[j] >> c[j];
			d[j]=a[j]+b[j]+c[j];
		}
		sort(d+1,d+n+1);
		int cnt1=0,cnt2=0,cnt3=0,cnt=0;
		for (int k=1;k<=n;k++){
			int j = search(d[k]);
			bool f=1;
			if (a[j]>=b[j]&&a[j]>=c[j]&&cnt1<=floor(n/2)&&f){
				cnt1++;
				cnt+=a[j];
				f=0;
			}
			if (a[j]<=b[j]&&b[j]>=c[j]&&cnt2<=floor(n/2)&&f){
				cnt2++;
				cnt+=b[j];
				f=0;
			}
			if (b[j]<=c[j]&&a[j]<=c[j]&&cnt3<=floor(n/2)&&f){
				cnt3++;
				cnt+=c[j];
				f=0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
