#include<bits/stdc++.h>
using namespace std;
int b[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string s; 
	cin>>s;
	string m;
	int num; 
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			m[i]=s[i];
		}
	}
	
	for(int i=0;i<=s.size();i++){
		if(m[i]>=m[i+1]){
			break;
		}
		else{
			m[i]=num;
			m[i]=m[i+1];
			m[i+1]=num;
		}
	} 
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
