#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector <long long >v;
	string s;
	cin>>s;
	long long l=s.size();
	long long a[l]={0};
	if(s.size()==1){
		cout<<s[0];
	}
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back((int)s[i]-48);
		}
	}
	for(long long i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i]<v[j]){
				long long temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		} 
	} 
	long long ll=v.size();
	for(long long i=0;i<ll;i++){
		cout<<v[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
