#include<bits/stdc++.h>
using namespace std;
int a[1010000],n,m,ans;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s.size();
	for(int i = 0; i <= m; i++){
		a[i+1]=s[i]-'0';//cout<<a[i]<<endl;
	}
//	cout<<endl<<endl<<endl;
	for(int i = 1; i <= s.size(); i++){
//		cout<<a[i]<<endl;
		if(a[i]>9||a[i]<0){
			a[i]=-1,m--;
		} 
	}
	sort(a+1,a+s.size()+1,cmp);
	for(int i = 1; i <= m; i++){
		cout<<a[i];
	}
	return 0;
} 
