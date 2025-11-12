#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a.push_back(s[i]-'0');
		}
	}
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]<a[j]){
				int mid=a[i];
				a[i]=a[j];
				a[j]=mid;
			}
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i];	
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
