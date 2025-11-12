#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout); 
	long long n,m,t=0;
	cin>>n>>m;
	
	char s[n];
	int c[n];
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	long long tot=1;
	for(long long i=1;i<=n;i+=1){tot*=i;
	if((tot)>998244353){
		t=t+tot%998244353;
		continue; 
	}
	}
	if(n<=20){
		cout<<tot%998244353;
	}else{
		cout<<t+tot%998244353;
	}
	
	return 0;
}

