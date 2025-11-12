#include<bits/stdc++.h>
using namespace std;
int ci[1005];
int main(){
	freopen("airplane.in","r",stdin);
	freopen("airplane.out","w",stdout);
	string s;
	string ss;
	cin>>s;
	ss=s;
	int l=0;
	int jh;
	int cd=0;

	for(int i=0;i<s.len();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ci[l]=s[i]-'0';
			l++;
			
		}
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(ci[j]<ci[j+1]){
				jh=ci[j];
				ci[j]=ci[j+1];
				ci[j+1]=jh;
			}
		}
	}
	for(int i=0;i<l;i++){
		cout<<ci[i];
	}

	return 0;	
} 
