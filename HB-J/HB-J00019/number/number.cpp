#include<bits/stdc++.h>
using namespace std;
string v;
int b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>v;
	int j=0,y=0;
	while((int)v[j]!=0){
		int m=(int)v[j];
		if(m>=48&&m<=57){
			b[y]=m-48;
			y++;
		}
		j++;
	}
	y--;
	for(int i=0;i<y;i++){
		for(int z=i+1;z<=y;z++){
			if(b[i]<b[z])
				swap(b[i],b[z]);
		}
	}
	for(int i=0;i<=y;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}
