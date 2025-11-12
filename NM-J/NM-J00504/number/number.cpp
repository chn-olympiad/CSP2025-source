#include <bits/stdc++.h>
using namespace std;
string a;
int numm[100005],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>a;
	sum=a.length();
	for(int i=0;i<sum;i++){
		if(int(a[i]==57))
			cout<<9;
		else
		numm[int(a[i])]++;
	}
	for(int i=56;i>=48;i--)
		for(int j=numm[i];j>0;j--)
			cout<<i-48;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

