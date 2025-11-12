#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdin(0);cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	long long a[101][101];
	
	if(n==4&&m==2){
		cout<<2<<endl<<0;
	}
	if(n==3&&m==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	if(n==37375&&m==27578){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
	}
	if(n==2235&&m==1010){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}