#include<bits/stdc++.h>
using namespace std;
string a;
int p[11],m=9;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if((a[i]-'0')>=0 && (a[i]-'0')<=9){
			p[a[i]-'0']++;
			
		}
	}
	while(m!=-1){
		if(p[m]>0){
			for(int j=1;j<=p[m];j++){
				cout<<m;
			}
		}
		m--;
	}
	fclose(stdin);
	fclose(stdout);
	return 1;
}

