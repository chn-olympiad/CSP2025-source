#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a=s.size(),c=0,k=-1;
	int x[a]={};
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	for(int i=0;i<a;i++){
		for(int j=0;j<10;j++){
			if(s[i]==b[j]){
				c=1;
				k++;
				break;
			}
			if(c==1){
				x[k]=j;
				c=0;
			}
		}
	}
	sort(x,x+a-1);
	for(int i=a-1;i>=0;i--){
		cout << x[i];
	}
	return 0;
}
