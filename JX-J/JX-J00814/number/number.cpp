#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	cin>>c;
	int n=c.length();
	int sum[10];
	memset(sum,0,sizeof(sum));
	for(long long i=0;i<n;i++){
		if(c[i]>='0'&&c[i]<='9'){
			if(c[i]=='0') sum[0]++;
			else if(c[i]=='1') sum[1]++;
			else if(c[i]=='2') sum[2]++;
			else if(c[i]=='3') sum[3]++;
			else if(c[i]=='4') sum[4]++;
			else if(c[i]=='5') sum[5]++;
			else if(c[i]=='6') sum[6]++;
			else if(c[i]=='7') sum[7]++;
			else if(c[i]=='8') sum[8]++;
			else sum[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(sum[i]>0){
			for(int j=1;j<=sum[i];j++) cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
