#include<bits/stdc++.h> 
using namespace std;
string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	long long shu[s.size()];
	//for(int i=1; i<=s.size(); i++){
	//	if(s.size(i)>='0'||s.size(i)<='9'){
	//		shu[n]+=i;
	//	}
	//}
	if(s.size()==1){
		cout<<s;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
