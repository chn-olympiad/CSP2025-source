#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),t=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i];
			t++;
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<=i;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}	
	}
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
