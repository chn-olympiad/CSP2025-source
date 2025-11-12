#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char j,b;
	char n[1000005],m[1000005];
	string s;
	int i=0,i1=0,a,i2,max_i;
	cin>>s;
	a=s.size();
	while(i<=a){
		j=s[i];
		if(j>='0' && j<='9'){
			n[i1]=j;
			i1++;
		}
		i++;
	}
	
	for(int k=0;k<i1;k++){
		char max='0';
		max_i=-1;
		for(int x=0;x<i1;x++){
			if(n[x]>max){
				max=n[x];
				max_i=x;
			}
		}
		m[k]=max;
		n[max_i]='0';
	}
	
	for(int k=0;k<i1;k++) cout<<m[k];
	return 0;
}
