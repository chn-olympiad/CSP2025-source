#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()];
	int b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=int(s[i])-'0';
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			if(a[i]>a[j]&&i!=j){
				int m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
	int ans=0;
	for(int i=0;i<b;i++){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
}
