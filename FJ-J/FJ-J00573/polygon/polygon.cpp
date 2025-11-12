#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],ans=0;
bool tmp=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]>1) tmp=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	if (n==3){
		if (s[n]>a[3]*2){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	if (n<3){
		cout << 0;
		return 0;
	}
	if (tmp==0){
		int k=1;
		while(a[k]==0){
			k++;
		}
		for(int i=3;i<=n-k+1;i++){
			int sum=n-k+1,ss=1,ii=i;
			if (ii>(n-k+1)/2) ii=n-k+1-ii;
			for(int j=1;j<=ii;j++){
				ss*=sum/j;
				sum--;
			}
			ans+=ss;
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int sum=s[j]-s[i-1];
			if (sum>a[j]*2) ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
