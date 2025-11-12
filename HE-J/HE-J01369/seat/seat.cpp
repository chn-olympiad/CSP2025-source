#include<bits/stdc++.h>
using namespace std;
long long n,m,a[150],l;
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) l=1;
		else if(a[i]>a[1]) l++; 
	}
	cout<<(l-1)/n+1<<" "<<( ((l-1)/n+1)&1 ? ((l-1)%n)+1 : n-((l-1)%n) );
	return 0;
}//期望得分 100,O(nm)
