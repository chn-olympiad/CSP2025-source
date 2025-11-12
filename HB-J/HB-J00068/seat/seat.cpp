#include <bits/stdc++.h>
using namespace std;
ifstream fin("seat.cpp");
ofstream fout("seat.cpp");
int n,m,a[105];
int main(){
	fin>>n>>m;
	for (int i=1;i<=n*m;i++) fin>>a[i];
	int ans=a[1],b;
	sort(a+1,a+n*m+1);
	int c=1;
	for (int i=n*m;i>=1;i--){
		if (a[i]==ans){
			b=c;
			break;
		}
		c++;
	}
	int l,h;
	if (b%n!=0) l=b/n+1;
	else l=b/n;
	h=b%n;
	if (l%2!=0){
		if (h!=0) fout<<l<<" "<<h;
		else fout<<l<<" "<<m;
	}
	else{
		int j=1;
		if (h==0){
			fout<<l<<" "<<1;
			return 0;
		}
		for (int i=m;i>=1;i--){
			if(h==i){
				fout<<l<<" "<<j;
				break;
			}
			j++;
		}
	}
	return 0;
}
