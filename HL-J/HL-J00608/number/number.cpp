#include<bits/stdc++.h>  
#include<vector> 
using namespace std;
bool cmpo1(int b,int a){
	return b>a;
}
string s;
int n;
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> b;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if( s[i]>='0' && s[i]<='9'){
			b.push_back(s[i]-'0');
		}
	}
	sort(b.begin(),b.end(),cmpo1);
	for(int i=0;i<s.size();i++){
		if( s[i]>='0' && s[i]<='9'){
			n=n*10+b[i];
		}
	}
	cout<<n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}