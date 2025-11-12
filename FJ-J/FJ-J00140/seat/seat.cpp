#include <bits/stdc++.h>  
using namespace std;
int n,m,x,g[15][15];
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >>n >>m;
	vector<int> a(n*m);
	bool f=0;
	for(int i=0;i<n*m;i++){
	    cin >>a[i];
	    if(f==0) x=a[i];
	    f=1;
	}
	sort(a.rbegin(),a.rend());
	int cnt=0,k=0;
	for(int i=0;i<n;i++){
		cnt++;
		if(cnt%2==1) for(int j=0;j<m;j++) g[j][i]=a[k++];
		else for(int j=m-1;j>=0;j--) g[j][i]=a[k++];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		    if(g[i][j]==x) cout <<j+1 <<" " <<i+1;	    
	    }
	}
	return 0;
}
