#include<bits/stdc++.h>
using namespace std;
int n,zh;
int num[5005]={0};
int a[5005];
void cx(){
	for (int i=1;i<=n;i++){
		num[i]=i;
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cx;
	for (int i=3;i<=n;i++){//n±ßÐÎ 
		int sum=0;
		while (num[1]<n-i+1){
			for (int j=1;j<=i;j++){
				sum+=a[j]£»	
			}
			if (sum>2*a[i]){
				zh++;
			}
			num[i]++;
			int t;
			if (num[i]>n){
				for (int j=i;j>1;j++){
					if (num[j]>n){
						num[j-1]++;
						t=j-1;
					}
				}
				for (int j=t+1;j<=i;j++){
					num[j]=num[j-1]+1;
				}
			}
		}
		cx;	
	}
	cout<<zh;
	return 0;
}
