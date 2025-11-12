#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	double m=1,n=0,a[1000005],sum=0;
	cin>>s;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i])+1;
			n++;
		}
	}
	for(int i=0;i<=n;i++){
		int min=11;
		for(int j=0;j<s.length();j++){
			if(a[i]!=0&&a[i]<min){
				min=a[i]-1;
				a[i]=0;
			}
		}
		sum+=(min*pow(10,n));
	}
	cout<<sum<<endl;
	return 0;
} 
