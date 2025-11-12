#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int num = 0;
	cin >> n >> q;
	string a1[n],a2[n];
	string q1[q],q2[q];
	for(int i = 0;i < n;i++)
		cin >> a1[i] >> a2[i];
	for(int i = 0;i < q;i++) 
		cin >> q1[i] >> q2[i];
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= q;j++){
			if(a1[i] == q1[j] || a1[i] == q2[j])
				score++;
			if(a2[i] == q1[j] || a2[i] == q2[j])
				score++; 
		}
}
	cout << score << endl;
	return 0;
}
