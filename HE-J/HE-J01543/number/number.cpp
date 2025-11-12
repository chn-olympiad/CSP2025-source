#include<bits/stdc++.h> 
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string f;
	cin>>f;
	int k=0;
	for(int i=0;i<f.size();i++){
		if(f[i]<='9' && f[i]>='0'){
			a[k]=f[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
