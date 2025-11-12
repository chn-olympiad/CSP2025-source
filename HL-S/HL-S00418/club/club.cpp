#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t=0;
	cin >> t;
	int answer[100001] = {};
	for(int p=0;p<t;p++){
		
		
		int n=0;
		cin >> n;
		int a[n][3] = {};
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin >> a[i][j];
			}
		}
		int aq[n/2][3] = {};
		int k=0;
		int r=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(k<=a[j][i]){
					k=a[j][i];
					aq[r][i] = max(k,aq[i][j]);
					if (k>aq[r][i]){
						r++;
						
					} 
				}
			}
			k=0;
			r=0;
		}
		int ans=0;
		for(int i=0;i<n/2;i++){
			for(int j=0;j<3;j++){
				ans+=aq[i][j];
			}
		}
		
		answer[p] = ans;
	
		
	}
	for(int i=0;i<t;i++){
		cout << answer[i] <<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
