#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int set1[n+1];
	for(int i = 1;i<=n;i++){
		cin >> set1[i];
		}
		int f=0;
	for(int i = 1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int z=set1[i];
			for(int k =i+1;k<=j;k++){
				z=!(z&set1[k]);
				}
				if(z==k){
					f++;
					}
			}
		}
		cout << f;
		return 0;
	}
