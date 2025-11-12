#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,ls;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				sum++;
				ls = 0;
			}else{
				if(ls){
					ls = 0;
					sum++;
				}else{
					ls++;
				}
			}
		}
	}else if(k == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1){
				sum++;
			}
		}
	}printf("%d",sum);
	return 0;
}
