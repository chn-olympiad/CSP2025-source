#include<bits/stdc++.h>
using namespace std;
const int Maxs = 15;
int lis[Maxs];
bool cmp(char a, char b){
	return a>b;
}
void read(){
	char a;
	while(cin>>a){
		if(a>='0'&&a<='9')lis[a-'0']++;
	}
}
int main()
{
	read();
	
	for(int i = 9;i>=0;i--){
		if(lis[i]>0){
			for(int j = 0;j<lis[i];j++){
				cout<<i;
			}
		}
	}
	return 0;	
} 
