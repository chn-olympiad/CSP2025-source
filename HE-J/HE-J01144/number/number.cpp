#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000011];
	cin>>s;
	int len=s.size(),sum=0;
	for(int i=0;i<len;++i){
		if (s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			sum++;
		}
		else{
			continue;
		}
		cout<<a[i];
	}
//	cout<<sum<<" "; 
//	char b[1000001],maxx=-10000000;
	fclose(stdin);
	fclose(stdin);
	return 0;
}
