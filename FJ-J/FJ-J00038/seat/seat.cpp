#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,grade = 1,a1;
	cin >> n >> m >> R;
	for(int i = 1;i<= n*m-1;i++){
		cin >> a1;
		if(a1> R) grade++;
	}
	cout << R << ' '<< grade << endl;
	int l = ceil(grade/(m*1.0));
	if(l % 2 == 1) cout << l<< ' ' << n-(3*l-grade);
	else cout << l << ' '<< m*l-grade+1;
	return 0;
}
