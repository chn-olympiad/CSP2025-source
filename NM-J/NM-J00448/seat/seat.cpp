#include <bits/stdc++.h>
using namespace std;

int n,m,mid,a[15][15],aaa,q;
int s[200];
int dn[20] = {1,-1,1,-1,10,-1,1,-1};
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int l = m*n;
	int r[15] = {n,1,n,1,n,1,n,1,n,1,n,1};
	for(int i=1;i<=l;i++){
		cin  >> s[i];
	}
	aaa = s[1];
	sort(s+1,s+l+1,cmp);
	int x=1,y=1,z=1;
	r[0] = n;
	while(q<=1){
		a[y][x] = s[q];
		if(a[y][x]==aaa){
			break;
		}
		if(y = r[mid]){
			x++;
			mid++;
		}else{
			y+=dn[mid];
		}
		q++;
	}
	cout << x << " " << y;
	return 0;
}
