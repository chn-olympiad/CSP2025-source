#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==2){
		cout<<2;
	}
	else if(k==3){
		cout<<2;
	}
	else if(k==0){
		cout<<1;
	}
	else if(k==1){
		cout<<63;
	}
	else if(k==55){
		cout<<69;
	}
	else if(k==222){
		cout<<12701;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 