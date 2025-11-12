#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	cin >> c;
	int n[11]={0};
	for (long long i=0;i<=1000;i++){
		if(int(c[i])<=57&&int(c[i])>=48)
		{
			n[int(c[i])-48] += 1;
		}
	}
	for (int i=10;i>=0;i--){ 
		while(n[i]>0){
			cout<<i;
			n[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}