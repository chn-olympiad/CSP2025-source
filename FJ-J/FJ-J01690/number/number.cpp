#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int a[100000005];
	long long sum=0;
	string s1;
	cin>>s1;
	long long vss=s1.length();
	for(long long i=0;i<vss;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			sum++;
			a[sum]=s1[i]-48;
			
		}
	}sort(a+1,a+sum+1);
	
	for(long long j=sum;j>=1;j--){
		cout<<a[j];
	}
	return 0;
	
    fclose(stdin);
	fclose(stdout);
}
