#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b;
int main(){
	freopen("seat.in","r"stdin);
	freopen("seat.out","w"stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>=a[i])b++;
	}
	
		
	}
	cout<<b/a+1<<" ";
	return 0;
	
}
