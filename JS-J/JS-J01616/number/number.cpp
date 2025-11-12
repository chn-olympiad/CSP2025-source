#include<bits/stdc++.h>
std::ifstream("number.in");
std::ofstream("number.out");
int main(){
	int a[1000001],n=0;
	char c;
	while(fin>>c){
		if(c>='0'&&c<='9'){
			n++;
			a[n]=(int)(c-'0');	
		}
	}
	std::sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		fout<<a[i];
	}
	return 0;
}
