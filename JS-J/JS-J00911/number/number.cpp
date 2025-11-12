#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof a);
	cin>>s;
	for(char c:s){
		if(c == '0'){
			a[0]++;
		}if(c == '1'){
			a[1]++;
		}if(c == '2'){
			a[2]++;
		}if(c == '3'){
			a[3]++;
		}if(c == '4'){
			a[4]++;
		}if(c == '5'){
			a[5]++;
		}if(c == '6'){
			a[6]++;
		}if(c == '7'){
			a[7]++;
		}if(c == '8'){
			a[8]++;
		}if(c == '9'){
			a[9]++;
		}
	}
	int r = 9;
	while(r>=0){
		if(a[r]!=-1){
			cout<<r;
			a[r]--;
		}if(a[r] == -1){
			r--;
		}
	}
	return 0;
}
