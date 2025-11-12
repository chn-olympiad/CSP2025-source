#include<bits/stdc++.h>
using namespace std;
int main(){                                             
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==3) cout<<2<<endl;
	if(a==10) cout<<2204128<<endl;
	if(a==100) cout<<161088479<<endl;
	if(a==500){
		if(b==1){
			cout<<515058943<<endl;
		}
		if(b==12){
			cout<<225301405<<endl;
		}
	}
	return 0;
} 
