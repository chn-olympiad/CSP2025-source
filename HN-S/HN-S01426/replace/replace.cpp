#include<bits/stdc++.h>
using namespace std;
long long n,q,x2[200005],z[200005];
string x[200005],x1[200005],y[200005],y2[200005];
int main(){
	freopen("replace.in",'r',stdin);
	freopen("replace.out",'w',stdout);
	cin >> n >> q;
	for(long long i = 0;i < n;i++){
		cin >> x[i] >> x1[i];
		long long a = 0;
		for(int j = 0;j < x[i].size();j++){
			if(x[i][j] != x1[i][j]){
				a++;
			}
		}
		x2[i] = a;
	}
	for(long long i = 0;i < q;i++){
		cin >> y[i] >> y2[i];
	}
	for(long long i = 0;i < q;i++){
		for(long long j = 0;j < n;j++){
			if(x[j] == y[i]){
				z[i] = x2[j];
			}
		}
	}
	for(long long i = 0;i < q;i++){
		cout << z[i] << endl; 
	}
	return 0;
}
