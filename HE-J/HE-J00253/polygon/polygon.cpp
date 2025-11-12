#include<bits/stdc++.h>
using namespace std;
int a,b,c[500050]={},e=0;
bool d[500050];
int main(){
	//freopen("xor1.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(c[i]==b){
			e++;
			d[i]=true;
		}
	}
	for(int i=1;i<=a;i++){
		int p=0; 
		if(!d[i]){
			p=(p xor i);
			if(p==b)
		}
	}
	cout<<e;
	//fclose(stdin);
	//fclose(stdout);

	return 0;
}
