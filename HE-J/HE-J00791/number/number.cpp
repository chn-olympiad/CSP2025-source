#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int n1=0;
	
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n1++;
		}
	}
	int s1[n1];
	int q=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[q]=s[i]-'0';
			q++;	
		}
	}
	for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++){
			if(s1[i]>s1[j]){
				swap(s1[i],s1[j]);
				
			}
		}		
	}		
	for(int i=0;i<n1;i++){
		cout<<s1[i];		
	}	
	return 0;
}
