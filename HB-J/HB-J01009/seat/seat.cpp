#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n*m],s[2]={1,1},d=0;
	cin >> a[0];
	for(int i=1;i<n*m;i++){
		cin >> a[i];
		if(a[i]>a[0])
			d++;
	}
	for(;d>0;d--){
		if(s[0]%n==1)
			s[1]++;
		if(s[0]%n==0)
			s[1]--;
		if(s[1]==n+1){
			s[0]++;
			s[1]--;
		}
		if(s[1]==0){
			s[0]++;
			s[1]++;
		}
	}
	cout << s[0] << " " << s[1] << endl;
	return 0;
}
