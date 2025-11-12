#include<bits/stdc++.h>
using namespace std;
int main() {
	FILE* in=freopen("seat.in","r",stdin);
	FILE* out=freopen("seat.out","w",stdout);
	int n,m,mine;
	int pri = 0;
	int buff;
	cin>>n>>m>>mine;
	
	for(int g=0;g!=n*m;++g){
		cin>>buff;
		if(mine<buff)
			++pri;
	}
	++pri;
	int resm = (pri%n==0)?(pri/n):((pri/n)+1);
	int resn=0;
	if(resm%2==0)
		resn=n-pri%n+1;
	else{
		resn=pri-(resm-1)*n;
	}
	if(resn==0)
	{
		resm--;
		resn=n;
	}
	cout<<resm<<' '<<resn;
	fclose(in);
	fclose(out);
	return 0;
} 
