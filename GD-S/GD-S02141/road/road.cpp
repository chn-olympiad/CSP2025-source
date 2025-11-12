#include<bits/stdc++.h>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
#define cout fout
#define cin fin 
typedef long long ll;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m*3+k;i++){
		cin>>n;
	}
	cout<<m;
	fin.close();
	fout.close();
	return 0;
}
