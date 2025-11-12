#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
vector<int>an;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	long long i=0;
	while(i<s.size()){

		if(s[i]-'0'<=9 and s[i]-'0'>=0){
		
			a[s[i]-'0']++;
		}
		i++;
	}

	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				an.push_back(i);	
			}
		}
	}
	i=0;
	while(i<an.size()){
		cout<<an[i];
		i++;
	}
	return 0;
}
