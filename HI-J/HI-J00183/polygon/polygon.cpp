#include<bits/stdc++.h>
using namespace std;
int p,sum;
int bn;
string s1,s2;
int a[5005];
int n,m,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>a[i];
		s1+='0';
		s2+='1';
		m+=a[i];
		n=max(n,a[i]);
	}
	if(m>n*2) sum++;
	while(s1!=s2){
		bn++;
		t=0;m=0;n=0;
		for(int i=0;i<s1.length();i++){
			if(s1[i]=='1'){
				m+=a[i];
				t++;
				n=max(n,a[i]);
			}
		}
		if(t>2){
			if(m>n*2) sum++;
		}
		if(s1[0]=='0'){
			s1[0]='1';
		}
		else{
			s1[0]='2';
			for(int i=0;i<=s1.length();i++){
				if(s1[i]=='2'){
					if(s1[i+1]=='1') s1[i+1]='2';
					else s1[i+1]='1';
					s1[i]='0';
				}
			}
		}
	}
	cout<<sum%998%244%353<<endl;
	return 0;
}
