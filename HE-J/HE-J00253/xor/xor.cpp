#include<bits/stdc++.h>
using namespace std;
int a,b,c[500050]={},e=0;
bool d[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(c[i]==b){
			e++;
			d[i]=true;
		}
	}
	int st=1,p=0;
	for(int i=st;i<=a;i++){
		if(!d[i]&&c[i]!=0){
			p=(p xor i);
			if(p==b){
				e++;
				st=i+1;
				p=0;
			}
		}
	}
	cout<<e;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
