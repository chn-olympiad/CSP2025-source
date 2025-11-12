#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum1=0;
	cin>>n>>k;
	int left=1,right;
	int a[100000];
	int map1[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		map1[i]=a[i];
	}
	while(left<=n){
		if(map1[left]==k){
			sum1++;
			left++;
			continue;
		}
		else{
			for(right=left+1;right<=n;right++){
				map1[right]^=map1[right-1];
				if(map1[right]==k){
					sum1++;
					left=right+1;
					break;
				}
			}
			continue;
		}
	}
	cout<<sum1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

