#include<bits/stdc++.h>
using namespace std;
string s[1000000][2];
int a[1000000][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> s[i][0];
		cin >> s[i][1];
	}
	
	for(int i=0;i<n;i++){
		int l1 = s[i][0].size();
		int tmp1,tmp2;
		
		for(int j=0;j<l1;j++){
			if(s[i][0][j] == 'b'){
				tmp1 = j;
				break;
			}
		}
		for(int j=0;j<l1;j++){
			if(s[i][1][j] == 'b'){
				tmp2 = j;
				break;
			}
		}
		a[i][0] = tmp2-tmp1;
		a[i][1] = tmp1;
		a[i][2] = l1;
	}
	while(q--){
		string s1,s2;
		int qs[2],ans = 0;
		cin >> s1 >> s2;
		int l1 = s1.size();
		for(int i=0;i<l1;i++){
			if(s1[i] == 'b'){
				qs[0] = i;
				break;
			}
		}
		for(int i=0;i<l1;i++){
			if(s2[i] == 'b'){
				qs[1] = i;
				break;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i][1] <= qs[0] && l1 >= a[i][2] && a[i][2]-a[i][1]+1 <= l1-qs[0]+1){
				if(a[i][0] == qs[1] - qs[0]) {
					ans++;
				}
				
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
