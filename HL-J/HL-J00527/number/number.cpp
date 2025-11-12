#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int cop(char n){
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	for(int i=0;i<0;i++){}
	for(int i=0;i<0;i++){}
	string s;
	string s1;
	string s2;
	cin>>s;
	s1=s;
	long long n=s.size();
	long long a[10001];
	for(long long i=0;i<n;i++){
		if(s1[i]>='a'&&s1[i]<='z'){
			s1[i]=s1[i+1];
		}
		s2[i]=s[i];
		
		//if(s2[i]<s2[i+1]){
		//	s1[i]=s1[i+1];
		//	s1[i+1]=s2[i];
		//}
	}
	for(int j=0;j<n;j++){
		for(long long i=0;i<n;i++){
			if(s1[i]<s1[i+1]){
				long long x=s1[i];
				s1[i]=s1[i+1];
				s1[i+1]=x;
			}
		}
	}
	
	//sort(s1.begin(),s1.)
	for(long long i=0;i<n;i++){
		cout<<s1[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}