#include<cstdio>
#include<string>
#include<iostream>

std::string str;
int a[1000100];
 
int main(){
	std::freopen("number.in","r",stdin);
	std::freopen("number.out","w",stdout);
	std::cin>>str;
	int r=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0'){
			a[r]=str[i]-48;
			r++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<r;j++){
			if(a[j]==i) printf("%d",a[j]);
		}
	}
	return 0;
} 
