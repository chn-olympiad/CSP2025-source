#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2,s3;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			s2+=s[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='9'){
			s3+=s2[i];
		}else{
			continue;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='8'){
			s3+=s2[i];
		}else{
			continue;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='7'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='6'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='5'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='4'){
			s3+=s2[i];
		}else{
			continue;
		}
		
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='3'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='2'){
			s3+=s2[i];
		}else{
			continue;
		}
	}  
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='1'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s2.size();i++){
		if(s2[i]=='0'){
			s3+=s2[i];
		}else{
			continue;
		}
	} 
	for(int i=0;i<s3.size();i++) a[i]=s3[i]-'0';
	for(int i=0;i<s3.size();i++) cout<<a[i];
	return 0;
} 
