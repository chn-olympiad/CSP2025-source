#include<bits/stdc++.h>
using namespace std;
bool ww(int a,int b){
	return a>b;
}
void f(vector<int>&a,int j){
	bool p=1;
	while(p){
		int o=0;
		for(int i=1;i<=j;i++){
		int k=i;
			while(k<j&&a[k]<a[k+1]){
				swap(a[k],a[k+1]);
				k++;
				o++;
			}
		}
		if(o==0)
		p=0;
	}
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>a(1000006);
	long long j=1;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[j]=(s[i]-'0');
			j++;
		}
	}
	f(a,j);
	if(a[1]==0){
		cout<<0;
	}else{
		for(int i=1;i<j;i++){
			cout<<a[i];
		}
	}
	return 0;
}