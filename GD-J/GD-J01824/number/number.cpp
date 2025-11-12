#include<bits/stdc++.h>
using namespace std;
int main() {
	FILE* in=freopen("number.in","r",stdin);
	FILE* out=freopen("number.out","w",stdout);
	char c;
	int n[10]={0,0,0,0,0,0,0,0,0,0};
	while(cin>>c){
		if(c == '0')
			n[0]++;
		else if(c == '1')
			n[1]++;
		else if(c=='2')
			n[2]++;
		else if(c=='3')
			n[3]++;
		else if(c=='4')
			n[4]++;
		else if(c=='5')
			n[5]++;
		else if(c=='6')
			n[6]++;
		else if(c=='7')
			n[7]++;
		else if(c=='8')
			n[8]++;
		else if(c=='9')
			n[9]++;
	}
	for(short nn=9;nn!=-1;--nn){
		for(long nnn=0;nnn!=n[nn];++nnn)
			cout<<nn;
	}
		
	fclose(in);
	fclose(out);
	return 0;
} 
