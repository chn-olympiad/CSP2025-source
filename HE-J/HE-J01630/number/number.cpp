#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int b[100005];int j=1;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			b[j]=s[i]-'0';
			j++;
		}
	}
	sort(b+1,b+j+1,cmp);
	for(int i=1;i<j-1;i++){
		cout<<b[i];
	}
	return 0;
} 
