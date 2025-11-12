#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int lena=a.size();
	vector<int> awa; 
	for(int i=0;i<lena;i++){
		if(a[i]>='0'&&a[i]<='9'){
			awa.push_back(a[i]-'0');
		}
	}
	sort(awa.begin(),awa.end());
	for(int i=awa.size()-1;i>=0;i--){
		printf("%d",awa[i]);
	}
	puts("");
	return 0;
}//RP++
