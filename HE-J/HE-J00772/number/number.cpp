#include<bits/stdc++.h>
using namespace std;
int c,s=1;
string w;
char v,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>w;
	c=w.size();
	for(int i=0;i<=c-1;i++){
		v=w[i];
		if(v<='9' && v>='0'){
			a[s]=v;
			cout<<a[s]<<" ";
			s++;
			
		}
	}
	sort(a,a+s);
	for(int i=s;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
