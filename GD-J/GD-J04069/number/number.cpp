#include<bits/stdc++.h>
using namespace std;

fstream("number.in","r",stdin);
fstream("number.out","w",stdout);
int vec[1000000];
bool Cmp(int a,int b){
	return a>=b;
}
int main(){
	char a;
	int c = 0;
	while(cin>>a){
		if('0'<=a&&'9'>=a){
			c++;
			vec[c]=a-'0';
		}
	}
	sort(vec+1,vec+c+1,Cmp);
	for(int i = 1;i<=c;i++){
		cout<<vec[i];
	}
	return 0;
} 
