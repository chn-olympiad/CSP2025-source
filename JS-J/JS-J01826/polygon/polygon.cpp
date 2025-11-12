#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a.begin(),a.end());
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	if(n==4){
		sort(a.begin(),a.end());
		int sum=4;
		if(a[1]+a[2]<=a[3])sum--;
		if(a[1]+a[2]<=a[4])sum--;
		if(a[1]+a[3]<=a[4])sum--;
		if(a[2]+a[3]<=a[4])sum--;
		int num=a[1]+a[2]+a[3]+a[4];
		if(num>2*a[4])sum++;
		cout<<sum;
		return 0;
	}
	if(n==5){
		sort(a.begin(),a.end());
		int s=10;
		if(a[1]+a[2]<=a[3])s--;
		if(a[1]+a[2]<=a[4])s--;
		if(a[1]+a[2]<=a[5])s--;
		if(a[1]+a[3]<=a[4])s--;
		if(a[1]+a[3]<=a[5])s--;
		if(a[1]+a[4]<=a[5])s--;
		if(a[2]+a[3]<=a[4])s--;
		if(a[2]+a[3]<=a[5])s--;
		if(a[2]+a[4]<=a[5])s--;
		if(a[3]+a[4]<=a[5])s--;
		int num=a[1]+a[2]+a[3]+a[4]+a[5];
		for(int i=1;i<=4;i++){
			num-=a[i];
			if(num>a[5]*2)s++;
			num+=a[i];
		}
		if(num-a[5]>2*a[4])s++;
		if(num>2*a[5])s++;
		cout<<s;
		return 0;
	}
}
