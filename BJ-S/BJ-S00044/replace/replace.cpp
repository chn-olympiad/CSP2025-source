#include<bits/stdc++.h>
using namespace std;
int n,q;
string th[200005][3],A,B,ls;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> th[i][1] >> th[i][2];
	}
	for(int i = 1;i <= q;i++){
		cin >> A >> B;
		A = A+"*";
		B = B+"*";
		int ans = 0;
		if(A.size() != B.size()){
			cout << 0 << endl;
		}
		else{
			for(int j = 0;j < A.size();j++){
				for(int k = 1;k <= n;k++){
					bool ok = 1;
					ls = A;
					for(int l = 0;l <th[k][1].size();l++){
						if(th[k][1][l] != A[j+l]){
							ok = 0;
							break;
						}
						ls[l+j] = th[k][2][l];
					}
					if(ok == 1 && ls == B){
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}