#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int arr1[maxn],arr2[maxn],arr3[maxn];
int idx1[maxn],idx2[maxn],arr3[maxn];
bool my_cmp(int x,int y){
	if(x > y) return y > x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	while(n--){
		int k;
		cin >> k;
		int mx1 = 0,mx2 = 0,mx3 = 0;
		for(int i = 1;i <= k;i++){
			cin >> arr1[i] >> arr2[i],arr3[i];
			if(mx1 < arr1[i]){
				mx1 = arr1[i];
				int idx1 = i;
			}
			if(mx2 < arr2[i]){
				mx2 = arr2[i];
				int idx2 = i;
			}
			if(mx3 < arr3[i]){
				mx3 = arr3[i];
				int idx3 = i;
			}
			sort(arr1+1,arr1+1+n,cmp);
			sort(arr2+1,arr2+1+n,cmp);
			sort(arr3+1,arr3+1+n,cmp);
		}
		for(int i = 1;i <= k;i++){
			idx1[i] = arr1[i];
			idx2[i] = arr2[i];
			idx3[i] = arr3[i];
		}
		sort(arr1+1,arr1+1+n,cmp);
		sort(arr2+1,arr2+1+n,cmp);
		sort(arr3+1,arr3+1+n,cmp);
		for(int i = 1;i <= k;i++){
			for(int j = 1;j <= k;j++){
				for(int s = 1;s <= k;s++){
					mx                     
				}
			}
		}
		
	}



	return 0;
}