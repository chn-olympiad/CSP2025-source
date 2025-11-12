//GZ-00052 华东师范大学附属贵阳学校 刘宇宸 
#include <bits/stdc++.h>
using namespace std;
int t,n;
long long a[100050][5],f1,f2,f3,k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		k= 0;
		f1 = 0;
		f2 = 0;
		f3 = 0;
		for(int i = 0;i <= 100005;i++){
			for(int j = 0;j < 5;j++){
				a[i][j] = 0;
			}
		}
		cin>>n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin>>a[i][j];
			}
			a[i][0] = max(a[i][1],a[i][2])-min(a[i][1],a[i][2])+max(a[i][1],a[i][3])-min(a[i][1],a[i][3])+max(a[i][3],a[i][2])-min(a[i][3],a[i][2]);
		}
		for(int i = 1;i <= n-1;i++){
			for(int j = i+1;j<=n;j++){
				if(a[i][0]<a[j][0] || (a[i][0] == a[j][0] && max(a[i][1],max(a[i][2],a[i][3]))<max(a[j][1],max(a[j][2],a[j][3])))){
					swap(a[i][0],a[j][0]);
					swap(a[i][1],a[j][1]);
					swap(a[i][2],a[j][2]);
					swap(a[i][3],a[j][3]);
				}
			}
		}
		for(int i = 1;i<=n;i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				if(f1 < n/2){
					f1++;
					k += a[i][1];
					continue;
				}else if(a[i][2] >= a[i][3]&&f2 < n/2){
					f2++;
					k += a[i][2];
					continue;
				}else{
					f3++;
					k += a[i][3];
					continue;
				}
			}
			if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				if(f2 < n/2){
					f2++;
					k += a[i][2];
					continue;
				}else if(a[i][1] >= a[i][3]&&f1 < n/2){
					f1++;
					k += a[i][1];
					continue;
				}else{
					f3++;
					k += a[i][3];
					continue;
				}
			}
			if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1]){
				if(f3 < n/2){
					f3++;
					k += a[i][3];
					continue;
				}else if(a[i][2] >= a[i][1]&&f2 < n/2){
					f2++;
					k += a[i][2];
					continue;
				}else{
					f1++;
					k += a[i][1];
					continue;
				}
			}
		}
		cout<<k<<endl;
	}
	
	return 0;
}

