#include<bits/stdc++.h>
using namespace std;
string s;
int l[1000005];

int maxn=0;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int a=s.length();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[int(s[i]-'0')]++;
			if(int(s[i]-'0')>maxn){
				maxn=int(s[i]-'0');
				
				
			}
			
		}
		
	}
	for(int i=maxn;i>=0;i--){
		if(l[i]!=0){
			for(int j=1;j<=l[i];j++){
				cout<<i;
			}
			
		}
	}





	return 0;
}
