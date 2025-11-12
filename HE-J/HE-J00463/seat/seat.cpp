#include <bits/stdc++.h>
using namespace std;
int a[15][15], c[110];
 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(NULL);
	
	int n, m, r;
	cin>>n>>m>>r;
	c[0]=r;
	for(int i = 1;i<n*m;i++) cin>>c[i];
	sort(c, c+n*m, greater<int>());
	int lie=0, hang=0, w=0;
	while(w<n*m){
		for(hang = 0;hang<n;hang++){
			if(w>=n*m) break;
			if(c[w]==r){
				cout<<lie+1<<' '<<hang+1;
				return 0;
			}
			w++;
		}
		lie++;
		for(hang = n-1;hang>=0;hang--){
			if(w>=n*m) break;
			if(c[w]==r){
				cout<<lie+1<<" "<<hang+1;
				return 0;
			}
			w++;
		}
		lie++;
	}
	cout<<lie+1<<' '<<hang+1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
