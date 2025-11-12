#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen ("number.in","r",stdin);
	//fclose ("number.out","w",stdout);
	
	string cd;
	int a=1,c=0,d=0,h=0;
	int b[200]={0};
	for(int i=0;i<a;i++){
		cin>>b[i];
		cin>>cd;
		a++;
		//cout<<cd;
		//cout<<b[0];
	}
	while (cin>>cd){
		c += 1; 
		if (cd[c]=='1'||cd[c]=='2'||cd[c]=='3'||cd[c]=='4'||cd[c]=='5'||cd[c]=='6'||cd[c]=='7'||cd[c]=='8'||cd[c]=='9'||cd[c]=='0'){
			a = cd[c]-'0';
			d += 1;
			b[d]=cd[c];	
		}
	}
	int min=b[0],max=0;
	for(int i=0;i<h;i++){
		if(min>b[i]){
			min = b[i];
		}
		if(max<b[i]){
			max = b[i];
		}
		
	}
	cout<<max;
	//cout<<cd;
	//cout<<b[1]<<b[2]<<b[3];
	return 0;
}
