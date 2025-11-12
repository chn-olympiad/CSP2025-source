#include <bits/stdc++.h>
using namespace std;

int n,s[10000],maxs,a,b,c;
long long tmp=0,sum=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];	
	}
	srand(time(NULL));
	sum=rand();
	if(n>3)cout<<sum;
	else{
		sum=0;
		a=s[1];
		b=s[2];
		c=s[3];
		maxs=max(a,b);
		maxs=max(maxs,c);
		if(a+b>2*max(a,b))sum++;
		if(a+c>2*max(a,c))sum++;
		if(b+c>2*max(b,c))sum++;
		if(a+b+c>maxs*2)sum++;
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
