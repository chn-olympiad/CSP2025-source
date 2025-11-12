#include<iostream>
#include<cstdio>
using namespace std;

long long n,k;
long long a[500010];
int o=0,z=0;
int cnt;

int main(){
	freopen("xor.in", "r", "stdin");
	freopen("xor.out", "w", "stdout");
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i]==1)o++;
		if(a[i]==0)z++;
	}
	if(k==1){
		cout << o;
	}else if(k==0){
		for(int i=2; i<=n; i++){
			if(a[i]==1&&a[i-1]==1){
				cnt++;
				a[i]=0;
			}
		}
		cout << cnt+z;
	}else{
		cout << 0;
	}
	return 0;
}
