#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x;
	vector<int> a;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<'A'){
			x=s[i]-'0';
			a.push_back(x);
			cnt++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
