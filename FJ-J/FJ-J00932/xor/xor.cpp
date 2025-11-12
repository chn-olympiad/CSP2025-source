#include<bits/stdc++.h>
using namespace std;

const int Max=5e5+10;
int n,k;
int a[Max],cnt=0,T=0,cnt2;
set<int> S;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=n-1;
	bool b=0;
	T=a[i]^k;
	int TT=a[i];
	if(T==0){
		cnt++;
		b=1;
	}
	while(i--){
		if(b){
			TT=a[i];
			b=0;
			T=a[i]^k;
			cnt2=1;
		}else{
			T=T^a[i];
			cnt2++;
		}
		if(T==0 || (T==TT && a[i]!=TT)){
			cnt++;
			b=1;
		}
//		for(auto j=S.begin();j!=S.end();j++){
//			cout<<*j<<" ";
//		}
//		cout<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
/*
13 1
 || S.size()!=cnt2
 || S.size()!=cnt2
*/
