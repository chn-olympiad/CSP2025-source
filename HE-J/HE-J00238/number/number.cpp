#include<iostream>
using namespace std;
string s;
int a[1000010]={0};
long long n=0;
int main(){
 	freopen("number4.in","r",stdin);
 	freopen("number4.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int j=0;j<n;j++){
		cout<<a[j];
	}
	return 0;
}

