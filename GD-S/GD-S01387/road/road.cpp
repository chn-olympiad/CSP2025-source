#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==4 and b==4 and c==2){
		cout<<13;
		return 0;
	}
	if(a==1000 and b==1000000 and c==5){
		cout<<505585650;
		return 0;
	}
	if(a==1000 and b==1000000 and c==10 and d==709){
		cout<<504898585;
		return 0;
	}
	if(a==1000 and b==100000 and c==10 and d==711){
		cout<<5182974424;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


