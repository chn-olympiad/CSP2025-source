#include<bits/stdc++.h>
using namespace std;
int n=0,k=0;
string s;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//cout<<s;
	n=s.length();
	for(int i=0;i<n;i++){
		//cout<<s[i]-'0'<<' ';
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[k+1]=s[i]-'0';
			//cout<<a[k+1]<<' ';
			//cout<<a[i+1]<<' '<<s[i]<<endl;
			k++;
		}
	}
	/*cout<<endl;
	for(int i=1;i<=k;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;*/
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0; 
}