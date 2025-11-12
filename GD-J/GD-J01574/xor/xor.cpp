#include<bits/stdc++.h> 
using namespace std;
int n,k,qq[510000],c;
long long f[510000];
struct asb{
	int x,y;
}qw[510000];

bool qd(asb a,asb b){
	return a.x<b.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<(5^6);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>qq[i];
	}
	for(int i=1;i<=n;i++){
		int lk=k;
		for(int j=i;j>=1;j--){
			if(lk==qq[j]){
				c++;
				qw[c]=(asb){j,i};
				//cout<<i<<" "<<j<<endl;
			}
			lk=(lk^qq[j]);
		}
	}
	sort(qw+1,qw+c+1,qd);
	for(int i=1;i<=c;i++){
		f[qw[i].y]=f[qw[i].x-1]+1;
		for(int j=qw[i].y;j<=n;j++){
			f[j]=f[qw[i].y];
		}
	}
	cout<<f[n];
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3


*/
