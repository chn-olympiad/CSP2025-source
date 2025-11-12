#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freogen("employ.in","r",stdin);
	freogen("employ.out","w",stdout);
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
