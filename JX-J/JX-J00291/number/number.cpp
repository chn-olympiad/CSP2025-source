#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s0;
	long long a[10],x[10],b,n;
	char c;
	cin>>s;
	for(int i=0;i<10;i++){
		a[i]=0;
		x[i]=0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			n++;
			c=s[i];
			b=c;
			x[b-48]=b;
			b-=48;
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j>0;j++){
			if(n!=0&&a[i]!=0){
				n--;
				a[i]--;
				s0+=x[i];
			}else{
				break;
			}
		}
		if(n==0){
			break;
		}
	}
	if(s0[0]=='0'){
		cout<<"0";
	}else{
		cout<<s0;
	}
	return 0;
}
