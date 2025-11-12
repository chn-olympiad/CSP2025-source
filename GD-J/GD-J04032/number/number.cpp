#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",in);
	freopen("number.out","w",out);
	string a;
	cin>>a;
	vector<long long>k;
	for(long long i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			k.push_back(a[i]-'0');
		}
	}
	sort(k.begin(),k.begin()+k.size());
	for(long long i=k.size()-1;i>=0;i--){
		cout<<k[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
