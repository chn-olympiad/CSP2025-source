#include<bits/stdc++.h>
using namespace std;

string a;
char b[10]={'0','1','2','3','4','5','6','7','8','9'};
int c[10]={0,0,0,0,0,0,0,0,0,0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k;
	cin>>a;
	for(i=0;i<a.length();i++){
		for(j=0;j<10;j++){
			if(a[i]==b[j]){
				c[j]++;
			}
		}
	}
	for(i=9;i>=0;i--){
		for(j=0;j<c[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
