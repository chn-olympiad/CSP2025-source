#include<bits/stdc++.h>
using namespace std;
int n[10];
string s;
void write(int k){
	if(k<0){
		putchar('-');
		k*=-1;
	}
	if(k>9)write(k/10);
	putchar(k%10+'0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9'){
			n[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]--)write(i);
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
