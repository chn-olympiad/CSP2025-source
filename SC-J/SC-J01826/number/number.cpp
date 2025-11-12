#include <bits/stdc++.h>
using namespace std;
string s;
long long A[20000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			A[(s[i]-'0')]++;
		}
	}
	bool b=0;
	for(int i=9;i>=0;i--){
		if(A[i]!=0){
			if(i>0){
				for(int j=1;j<=A[i];j++){
					cout<<i;
				}
				b=1;
			}else{
				if(b){
					for(int j=1;j<=A[i];j++){
						cout<<i;
					}
				}else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 