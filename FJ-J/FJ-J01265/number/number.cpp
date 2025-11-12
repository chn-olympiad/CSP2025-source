#include<bits/stdc++.h>
using namespace std;
int a[1000005],x;
int main(){//rp=INT_MAX;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+l,greater<int>());
	if(a[0]==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<x;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//time 11:45:14
