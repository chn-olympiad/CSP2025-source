#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char p;
	int n=0;
	while(cin>>p){
		if(p>='0' && p<='9'){
			n++,a[n]=p-'0';
			//cout<<n<<' '<<a[n]<<endl;
		}
	}
	//for(int i=1;i<=n;i++){
		//cout<<a[i]<<' ';
	//}
	//cout<<endl;
	sort(a+1,a+n+1);
	bool f=0;
	for(int i=n;i>=1;i--){
		f=(f||a[i]);
	}
	if(f){
		for(int i=n;i>=1;i--){
			cout<<a[i];
		}
		cout<<'\0';
	}
	else cout<<0<<'\0';
	return 0;
}
