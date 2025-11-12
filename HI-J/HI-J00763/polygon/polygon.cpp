#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a,maxn=0;
	int num=0,sum=0;
	for(int i=1;i<=n;i++){
		cin >> a;
		if(a>=maxn){
			maxn=a;
		}
		num+=a;
		if(num+a>maxn){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
