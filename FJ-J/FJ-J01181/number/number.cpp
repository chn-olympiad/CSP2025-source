#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int s0 = 0,s1 = 0,s2 = 0,s3 = 0,s4 = 0;
	int s5 = 0,s6 = 0,s7 = 0,s8 = 0,s9 = 0; 
	int b[1000010][1000010];
	string a;
	cin>>a;
	int n = a.size();
	for(int i = 0;i < n;i++){
		if((char)a[i] == '0'){
			b[i][s0]++;
			s0++;
		}
		else if((char)a[i] == '1'){
			b[i][s1]++;
			s1++;
		}
		else if((char)a[i] == '2'){
			b[i][s2]++;
			s2++;
		}
		else if((char)a[i] == '3'){
			b[i][s3]++;
			s3++;
		}
		else if((char)a[i] == '4'){
			b[i][s4]++;
			s4++;
		}
		else if((char)a[i] == '5'){
			b[i][s5]++;
			s5++;
		}
		else if((char)a[i] == '6'){
			b[i][s6]++;
			s6++;
		}
		else if((char)a[i] == '7'){
			b[i][s7]++;
			s7++;
		}
		else if((char)a[i] == '8'){
			b[i][s8]++;
			s8++;
		}
		else if((char)a[i] == '9'){
			b[i][s9]++;
			s9++;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= s9;j++)
			cout<<b[i][s9];
		for(int j = 0;j <= s8;j++)
			cout<<b[i][s8];
		for(int j = 0;j <= s7;j++)
			cout<<b[i][s7];
		for(int j = 0;j <= s6;j++)
			cout<<b[i][s6];
		for(int j = 0;j <= s5;j++)
			cout<<b[i][s5];
		for(int j = 0;j <= s4;j++)
			cout<<b[i][s4];
		for(int j = 0;j <= s3;j++)
			cout<<b[i][s3];
		for(int j = 0;j <= s2;j++)
			cout<<b[i][s2];
		for(int j = 0;j <= s1;j++)
			cout<<b[i][s1];
		for(int j = 0;j <= s0;j++)
			cout<<b[i][s0];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
