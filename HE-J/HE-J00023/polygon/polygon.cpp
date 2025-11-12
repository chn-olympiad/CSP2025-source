#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		int MAX=0;
		for(int i=1;i<=n;i++){
			if(a[i]>MAX) MAX=a[i];
		}
		if(cnt>(MAX*2)){
			cout<<1;
			return 0;
		}else cout<<'0';
	}else{
		cnt=0;
		for(int i=n;i>=3;i--){
			cnt=0;
			for(int j=i;j>=1;j--){
				cnt+=j;
				if(cnt>(i*2)) num++;
				}
			}
		}
		cout<<num;
	}
	
	return 0;
}
