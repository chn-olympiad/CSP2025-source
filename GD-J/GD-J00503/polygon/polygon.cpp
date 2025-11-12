#include<bits/stdc++.h>
using namespace std;

int a[50005];
int b[50005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int num = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = b[i-1]+a[i];
		for(int j = 1;j<i;j++){
			int k = b[i]-a[j];
			if(k>(a[i]*2)){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
