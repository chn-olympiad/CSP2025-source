#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('club.in','r',stdin);
	freopen('club.out','w',stdout);
	int a[100005][10],maxn=-1,maxi,maxx,maxii[100005],b=0,c=0,d=0;
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin >> a[j][k];
			}
			for(int k=0;k<3;k++){
				if(maxn < a[j][k]){
					maxn = a[j][k];
					maxi = k;
				}
			}
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(a[j][k] > a[j][l]){
						int e = a[j][k];
						a[j][k] = a[j][l];
						a[j][l] = e;
					}
				}
			}
			maxx += maxn;
			maxii[j] = maxi;
		}
		for(int j=0;j<n;j++){
			if(maxii[j] == 0){
				b++;
			}
			if(maxii[j] == 1){
				c++;
			}
			if(maxii[j] == 2){
				d++;
			}
		}
		while(d > n/2 || b > n/2 || c > n/2){
			if(d > n/2){
				for(int j=0;j<n;j++){
					if(maxii[j] == 2){
						maxx -= a[j][0];
						maxx += a[j][1];
						d--;
						break;
					}
				}
			}
			if(b > n/2){
				for(int j=0;j<n;j++){
					if(maxii[j] == 0){
						maxx -= a[j][0];
						maxx += a[j][1];
						b--;
						break;
					}
				}
			}
			if(c > n/2){
				for(int j=0;j<n;j++){
					if(maxii[j] == 1){
						maxx -= a[j][0];
						maxx += a[j][1];
						c--;
						break;
					}
				}
			}
		}	
		cout << maxx << endl;
	}
	return 0;
}

