#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define int long long
int a[10],v;
string n,ans;
signed main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.length();i++){
		if(n[i]>='0' && n[i]<='9'){
			a[n[i]-'0']++;
			v++; 
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			ans+=i+'0';
			a[i]--;
		}
	}
	if(!v){
		cout<<0<<endl;
	}else{
		cout<<ans<<endl;
	} 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
